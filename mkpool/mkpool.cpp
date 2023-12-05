#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#define FNAME   "tmp.txt"
#define MAX_CHAR	256

int main(int argc, char *argv[])
{
	FILE *fp = NULL;
	char *fname = NULL;
	char line[MAX_CHAR];
	char buf1[MAX_CHAR];
	char buf2[MAX_CHAR];
	int n1, n2;

	if (argc != 2) {
		printf("Usage: %s <file>\n\n", argv[0]);
		return -1;
	}

	fname = argv[1];
	if((fp = fopen(fname, "r")) != NULL) {
		while (fgets(line, sizeof(line), fp)) {
			n1 = n2 = 0;
			sscanf(line, "%[^\t] %d %d", buf1, &n1, &n2);
			sscanf(buf1, "%[^\t\( ]", buf2);
			// printf("'%s' '%s'\n", buf1, buf2);

			// printf("{DDR_ID0, '%s', '%d', '%d' },\n", buf2, n1, n2);
			printf("{DDR_ID0, %-40s, %-7d, %d },\n", buf2, n1, n2);
		}
		fclose(fp);
		printf("{(HD_COMMON_MEM_DDR_ID)-1, -1, -1, -1}\n\n");
	}

	return 0;
}
