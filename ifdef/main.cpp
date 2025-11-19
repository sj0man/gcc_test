#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#define FNAME   "tmp.txt"
#define MAX_CHAR	256



int file_write(FILE *fp, int cnt)
{
	char buf[MAX_CHAR];

	if((fp = fopen(FNAME, "a")) == NULL) {
		fprintf(stderr, "failed: %s\n", strerror(errno));
		return 1;
	}

	snprintf(buf, sizeof(buf), "%d: Hello World!\n", cnt);

	if (fputs(buf, fp) == 0) {
		fprintf(stderr, "failed: %s\n", strerror(errno));
	} else {
		printf("%s", buf);
	}

	fclose(fp);

	return 0;
}


int main(int argc, char *argv[])
{

#if defined(EXTRA_IPC) && (defined(NT9831X) || defined(NT9832X))
	puts("OK");
#else
	puts("NG");
#endif

#if defined(EXTRA_IPC)
	puts("EXTRA_IPC");
#endif

#if defined(NT9831X)
	puts("NT9831X");
#endif

#if defined(NT9832X)
	puts("NT9832X");
#endif

	return 0;
}