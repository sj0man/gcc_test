#include <stdio.h>
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

	if((fp = fopen(FNAME, "r")) != NULL) {
		while (fgets(buf, sizeof(buf), fp)) {
			count++;
			printf("%s", buf);
		}
		fclose(fp);	
	}

	if (file_write(fp, count) == 1)
		return 1;

	return 0;
}