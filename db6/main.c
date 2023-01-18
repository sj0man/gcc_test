#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#include <arpa/inet.h>

#include "db.h"

// #define FNAME   "/data0/data.db6"
#define FNAME   "./data.db6"

#define	DB6_VERSION			(0x0610)
#define DB6_MAGIC			(('d'<<24) | ('b'<<16) | ('5'<<8))

#define	DMD_VERSION_0610	(0x0610)
#define	DMD_VERSION_0620	(0x0620)
#define DMD_MAGIC			(('d'<<24) | ('m'<<16) | ('d'<<8))


#define off_t   long int
#define size_t  long int

int pread_db6_head(int fd, db6_head_t *head, size_t sz, off_t off)
{
	db6_head_t	h;
	int size;

	size = pread(fd, &h, sz, off);
	if (size != sizeof(db6_head_t)) {
		return 0;
	}

	head->magic = ntohl(h.magic);
	head->version = ntohs(h.version);
	head->rev = ntohs(h.rev);
	head->num_day = ntohl(h.num_day);
	head->off_date = ntohl(h.off_date);
	head->off_free_date = ntohl(h.off_free_date);
	head->reserved = ntohl(h.reserved);

	return size;
}

__u64 htonll(__u64 host_longlong)
{
	return ((((__u64)htonl(host_longlong)) << 32) + htonl(host_longlong >> 32));
}
 
__u64 ntohll(__u64 host_longlong)
{
	return ((((__u64)ntohl(host_longlong)) << 32) + ntohl(host_longlong >> 32));
}


int pread_db6_date(int fd, db6_date_t *date, size_t sz, off_t off)
{
	db6_date_t	d;
	int ssize;

	ssize = pread(fd, &d, sz, off);
	if (ssize != sizeof(db6_date_t)) {
		return 0;
	}

	memcpy(date, &d, sizeof(db6_date_t));

	date->magic = ntohl(d.magic);
	date->id = ntohl(d.id);
	date->off_next = ntohl(d.off_next);
	date->year = ntohs(d.year);

	int k;
	for (k = 0; k < NUM_EL6_TYPE; k ++) {
		if (d.num_el[k])
			date->num_el[k] = ntohl(d.num_el[k]);
	}

	int ch, h;
	for (ch = 0; ch < NUM_DB6_CH; ch ++) {
		for (h = 0; h < 24; h ++) {
			if (d.rec[ch][h])
				date->rec[ch][h] = ntohll(d.rec[ch][h]);
			if (d.event[ch][h])
				date->event[ch][h] = ntohll(d.event[ch][h]);
		}
	}

	return ssize;
}


int db6_check(const char *fname)
{
	int fd, ret;
	db6_head_t head;

	if ((fd = open(fname, O_RDONLY)) == -1) {
		fprintf(stderr, "ERROR: %s\n", strerror(errno));
		return -1;
	}

	ret = pread_db6_head(fd, &head, sizeof(db6_head_t), 0);

	// printf(
	// 	"magic:0x%08x, version:0x%04x\n", 
	// 	DB6_MAGIC,
	// 	DB6_VERSION
	// );

	printf(
		"magic:0x%08x (%c%c%c), version:0x%04x, rev:%d, num_day:%d, off_date:%d, off_free_date:%d, reserved:%d\n",
		head.magic, (char)((head.magic>>24) & 0xff), (char)((head.magic>>16) & 0xff), ((head.magic>>8) & 0xff),
		head.version,
		head.rev,
		head.num_day,
		head.off_date,
		head.off_free_date,
		head.reserved
	);
	
	db6_date_t	date;
	memset(&date, 0, sizeof(date));
	date.off_next = head.off_date;
	__u32 c;
	for (c=0; (c<head.num_day) && date.off_next; c++) {
		int off_date;
		off_date = date.off_next;

		ret = pread_db6_date(fd, &date, sizeof(db6_date_t), off_date);

		printf(
			"magic:0x%08x, id:%d, off_next:%d, year:%d, month:%d, mday:%d\n",
			date.magic,
			date.id,
			date.off_next,
			date.year,
			date.month,
			date.mday
		);
	}


	close(fd);
	return ret;
}


void db6_dump(const char *fname)
{
	printf("================ sizeof struct ================\n");
	printf("db6_head_t   =%lu\n", sizeof(db6_head_t));
	printf("db6_date_t   =%lu\n", sizeof(db6_date_t));

	int fd = -1;

	// 이미 존재하는 파일
	if ((fd = open(fname, O_RDONLY)) < 0) {
		printf("open() fail! errno=%d,\"%s\"\n", errno, strerror(errno));
		goto FAIL;
	}

	db6_head_t	head;

	// head 읽기
	if (pread_db6_head(fd, &head, sizeof(db6_head_t), 0) != sizeof(db6_head_t)) {
		printf("pread_db6_head() error! errno=%d,\"%s\"\n", errno, strerror(errno));
		goto FAIL;
	}

	printf("================ head ================\n");
	printf("magic        =%08X\n", head.magic);
	printf("version      =%x\n", head.version);
	printf("num_day      =%d\n", head.num_day);
	printf("off_date     =%d\n", head.off_date);
	printf("off_free_date=%d\n", head.off_free_date);

	db6_date_t	date;
	memset(&date, 0, sizeof(date));
	date.off_next = head.off_date;
	__u32 c;
	for (c = 0; (c < head.num_day) && date.off_next; c ++) {
		int off_date;
		off_date = date.off_next;

		if (pread_db6_date(fd, &date, sizeof(db6_date_t), off_date) != sizeof(db6_date_t)) {
			printf("pread_db6_date() error! errno=%d,\"%s\"\n", errno, strerror(errno));
			goto FAIL;
		}

		printf("  ================ date=%d off=%d ================\n", c, off_date);
		printf("  magic   =%08X\n", date.magic);
		printf("  id      =%d\n", date.id);
		printf("  date    =%d/%d/%d\n", date.year, date.month, date.mday);
		printf("  off_date=%d\n", date.off_next);
		// printf("  num_el  =%d\n", db6_num_el(&date));

		int k;
/*		
		printf("    ================ rec ================\n");
		for (k = 0; k < NUM_DB6_CH; k ++) {
			int hh;
			for (hh = 0; hh < 24; hh ++) {
				if (date.rec[k][hh])
					printf("    ch=%02x hour=%2d rec=%016llx\n", k, hh, date.rec[k][hh]);
			}
		}
		printf("    ================ event ================\n");
		for (k = 0; k < NUM_DB6_CH; k ++) {
			int hh;
			for (hh = 0; hh < 24; hh ++) {
				if (date.event[k][hh])
					printf("    ch=%02x hour=%2d event=%016llx\n", k, hh, date.event[k][hh]);
			}
		}
		printf("    ================ num_el ================\n");
		for (k = 0; k < NUM_EL6_TYPE; k ++) {
			if (date.num_el[k])
				printf("    type=%02x num_el=%d\n", k, date.num_el[k]);

		}
*/
		printf("    ================ chunk ================\n");
		for (k = 0; k < NUM_CHUNK; k ++) {
			if (date.chunk[k].valid) {
				printf("    chunk=%3d bookmark=%d hdd=%d valid=%d\n", k, date.chunk[k].bookmark, date.chunk[k].hdd, date.chunk[k].valid);
			}
		}
	}

	if (head.off_free_date) {
		printf("\n\n================ off_free_date ================\n");

		memset(&date, 0, sizeof(date));
		date.off_next = head.off_free_date;
		for (c = 0; date.off_next; c ++) {
			int off_date;
			off_date = date.off_next;

			if (pread_db6_date(fd, &date, sizeof(db6_date_t), off_date) != sizeof(db6_date_t)) {
				printf("pread_db6_date() error! errno=%d,\"%s\"\n", errno, strerror(errno));
				goto FAIL;
			}

			printf("  ================ free.. date=%d off=%d next=%d ================\n", c, off_date, date.off_next);
		}
	}

FAIL:
	if (fd >= 0)
		close(fd);
}


int main(void)
{
	printf("head:%ld, date:%ld\n", sizeof(db6_head_t), sizeof(db6_date_t));
	// db6_check(FNAME);

	db6_dump(FNAME);
	return 0;
}

