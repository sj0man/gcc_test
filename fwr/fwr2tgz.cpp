#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <sys/poll.h>
#include <termios.h>
#include <sys/ioctl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>
#include <sys/mman.h>
#include <sys/ioctl.h>
#include <asm/types.h>
#include <linux/videodev2.h>
#include <linux/fb.h>



#define SIZE_TXT	256
#define TMP_DIR					"./tmp"




/*************************************************************************
 *
 *************************************************************************/

static int _clone_fwr_file(char *fname, char *sz_dst)
{
	printf("_clone_fwr_file.. fname:%s sz_dst:%s\n", fname, sz_dst);

	int fd;
	char szfile[SIZE_TXT*2];
	sprintf(szfile, "%s", fname);
	if ((fd=open(szfile, O_RDONLY)) < 0)
	{
		printf("Open %s failed!! error:%s\n", fname, strerror(errno));
		return -1;
	}
	struct stat fs;
	fs.st_size = 0;
	fstat(fd, &fs);
	if (fs.st_size <= 0)
	{
		printf("Error!! %s size zeor!!\n", fname);
		close(fd);
		return -1;
	}
	unsigned char *tbuf;
	tbuf = (unsigned char *)malloc(fs.st_size);
	if (tbuf == NULL)
	{
		printf("malloc %ld failed!! error:%s\n", fs.st_size, strerror(errno));
		close(fd);
		return -1;
	}
	int l;
	if ((l=read(fd, tbuf, fs.st_size-4)) != (fs.st_size-4))
	{
		free(tbuf);
		close(fd);
		printf("read %ld, %d size mismatch!!\n", fs.st_size, l);
		return -1;
	}

	close(fd);

	if ((fd=open(sz_dst, O_RDWR|O_CREAT)) < 0)
	{
		return -1;
	}
	if ((l=write(fd, tbuf, fs.st_size-4)) != (fs.st_size-4))
	{
		printf("write error!!\n");
	}

	close(fd);

	free(tbuf);

	return 0;
}



int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		printf("usage.. fwr2tgz fwr\n");
		return 0;
	}
	if (strstr(argv[1], "fwr") == NULL)
	{
		printf("Invalid fwr file!!\n");
		return 0;
	}

	char szcmd[SIZE_TXT*2];
	sprintf(szcmd, "mkdir -p %s", TMP_DIR);
	system(szcmd);

	char szfwr[SIZE_TXT*2];
	sprintf(szfwr, "%s/fwr.tar.gz", TMP_DIR);

    _clone_fwr_file(argv[1], szfwr);

	sprintf(szcmd, "chmod 644 %s", szfwr);
    system(szcmd);

	// sprintf(szcmd, "rm -rf %s", TMP_DIR);
	// system(szcmd);

	return 0;
}

