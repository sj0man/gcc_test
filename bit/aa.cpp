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

int main(void)
{
	FILE *fp = NULL;
	char buf[MAX_CHAR];
	int count = 0;

	printf("(1<<0) = %04x\n", (1<<0));
	printf("(1<<1) = %04x\n", (1<<1));
	printf("((1<<0) | (1<<1)) = %04x\n", ((1<<0) | (1<<1)));
	printf("((1<<0) | (1<<2)) = %04x\n", ((1<<0) | (1<<2)));


	return 0;
}