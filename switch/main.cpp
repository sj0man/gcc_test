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
	int var = 4;

	switch (var) {
		case 1:
			printf("case 1\n");
			break;
		case 2:
			printf("case 2\n");
			break;
		case 3:
			printf("case 3\n");
			break;
			printf("leesj\n");		// unreachable code
		case 4:
			printf("case 4\n");
			break;
	}

	return 0;
}