#include <stdio.h>
#include <stdlib.h> // system
#include <string.h>
#include <errno.h>
#include <fcntl.h>  // open
#include <unistd.h> // write, fsync, close

#define FNAME       "/home/ubuntu/tmp/board_ok.txt"



int main(void)
{
	int k;
	for (k = 0; k < 5; k ++)
	{
		int fd;
        // 파일이 없으면 생성한다.
		fd = open(FNAME, O_RDWR|O_CREAT|O_TRUNC, S_IRWXU|S_IRWXG|S_IRWXO);
		if (fd >= 0)
		{
			write(fd, "ok", 3);
			fsync(fd);
			close(fd);
		}
		system("sync");
	}

	return 0;
}