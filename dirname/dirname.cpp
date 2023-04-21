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
#include <libgen.h>

#define SIZE_TXT	256

int main(void)
{
	// char szcmd[SIZE_TXT*2];
	char dest[SIZE_TXT] = "/usr/lib/libdal.so";
	char dirPath[SIZE_TXT] = "temp";


	strcpy(dirPath, dest);

	dirname(dirPath);
	printf("%s, %s\n", dest, dirPath);

	// sprintf(szcmd, "cd %s; ls", dirPath);
	// system(szcmd);


}