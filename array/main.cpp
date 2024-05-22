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


/*

*/
int main(int argc, char *argv[])
{
	int convert[] = {1, 2, 3, 4, 5};
	int ain = 1;

	printf("ain = %d\n", ain);
	ain = convert[3];
	printf("ain = %d\n", ain);
	ain = convert[10];
	printf("ain = %d\n", ain);


	return 0;
}