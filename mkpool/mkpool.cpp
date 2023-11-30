#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#define FNAME   "tmp.txt"
#define MAX_CHAR	256

/*
	(1) copy data from excel to text

	(2) replace by regular expression
		^([^\t\( ]+)[^\t]*\t(\d{1,})\t(\d{1,})
		\1, \2, \3

	(3) paste the replacement output into code.

	(4) compile and run

*/

int main(int argc, char *argv[])
{
	FILE *fp = NULL;
	char *fname = NULL;
	char line[MAX_CHAR];
	char buf1[MAX_CHAR];
	char buf2[MAX_CHAR];
	char buf3[MAX_CHAR];

	if (argc != 2) {
		printf("Usage: %s <file>\n\n", argv[0]);
		return -1;
	}

	fname = argv[1];
	if((fp = fopen(fname, "r")) != NULL) {
		while (fgets(line, sizeof(line), fp)) {
			sscanf(line, "%[^,], %[^,], %s", buf1, buf2, buf3);
			printf("{DDR_ID0, %-40s, %-6s, %s },\n", buf1, buf2, buf3);
		}
		fclose(fp);
	}

	return 0;
}
