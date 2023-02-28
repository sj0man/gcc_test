// hexa file size
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <errno.h>
#include <dirent.h>
#include <unistd.h>


const char *number2comma(size_t n)
{
	static char comma_str[64];
	char   str[64];
	int	idx, len, cidx = 0, mod;
	
	sprintf(str, "%ld", n);
	len = strlen(str);
	mod = len % 3;
	
	for(idx = 0; idx < len; idx++) {
		if(idx != 0 && (idx) % 3 == mod) {
			comma_str[cidx++] = ',';
		}
		comma_str[cidx++] = str[idx];
	}
	
	comma_str[cidx] = 0x00;
	return comma_str;
}

static size_t get_file_size (const char * file_name)
{
	struct stat sb;

	if ((errno=stat(file_name, & sb)) != 0) {
		fprintf(stderr, "'stat' failed for '%s': %s.\n", file_name, strerror (errno));
		exit(EXIT_FAILURE);
	}
	return sb.st_size;
}

const char *path = ".";

int all_check(void)
{
	int len, maxlen=0;
	const char * file_name;
	size_t size;

	struct  dirent **namelist;
	struct stat buf;
	int	 count;
	int	 idx;

	if((count = scandir(path, &namelist, NULL, alphasort)) == -1) {
		fprintf(stderr, "%s Directory Scan Error: %s\n", path, strerror(errno));
		return 1;
	}

	for(idx=1; idx<count; idx++) {
		lstat(namelist[idx]->d_name, &buf);
		if( S_ISDIR(buf.st_mode) )
			continue;
		file_name = namelist[idx]->d_name;
		len = strlen(file_name);
		if(len > maxlen)
			maxlen = len;
	}

	for(idx=1; idx<count; idx++) {
		lstat(namelist[idx]->d_name, &buf);
		if( S_ISDIR(buf.st_mode) )
			continue;
		file_name = namelist[idx]->d_name;
		size = get_file_size(file_name);
		printf("%*s: %12s %#lx\n", maxlen, file_name, number2comma(size), size);
	}
	printf("\n");

	// 건별 데이터 메모리 해제
	for(idx = 0; idx < count; idx++) {
		free(namelist[idx]);
	}

	// namelist에 대한 메모리 해제
	free(namelist);

	return 0;
}

int specific_check(int argc, char ** argv)
{
	int i, len, maxlen=0;
	const char * file_name;
	size_t size;

	for(i=1; i<argc; i++) {		
		file_name = argv[i];
		len = strlen(file_name);
		if(len > maxlen)
			maxlen = len;
	}

	for(i=1; i<argc; i++) {
		file_name = argv[i];
		size = get_file_size(file_name);
		printf("%*s: %12s %#lx\n", maxlen, file_name, number2comma(size), size);
	}
	printf("\n");
	return 0;
}

int main(int argc, char ** argv)
{
	int ret=0;

	if (argc == 1) {
		ret = all_check();
	} else {
		ret = specific_check(argc, argv);
	}
	return ret;
}
