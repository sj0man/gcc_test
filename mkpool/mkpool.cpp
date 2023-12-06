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
	char full_name[MAX_CHAR];
	char short_name[MAX_CHAR];
	int size0, cnt0, total0;
	int size1, cnt1;

	if (argc != 2) {
		printf("Usage: %s <file>\n\n", argv[0]);
		return -1;
	}

	fname = argv[1];
	if((fp = fopen(fname, "r")) != NULL) {
		while (fgets(line, sizeof(line), fp)) {
			size0 = cnt0 = size1 = cnt1 = 0;
			sscanf(line, "%[^\t] %d %d %d %d %d", full_name, &size0, &cnt0, &total0, &size1, &cnt1);
			sscanf(full_name, "%[^\t\( ]", short_name);

			// for debugging
			// printf("'%s' '%s' size0=%d cnt0=%d\n", full_name, short_name, size0, cnt0);

			printf("{DDR_ID0, %-40s, %-7d, %-3d },\n", short_name, size0, cnt0);
		}
		printf("\n");
		fclose(fp);

		fp = fopen(fname, "r");
		while (fgets(line, sizeof(line), fp)) {
			size0 = cnt0 = size1 = cnt1 = 0;
			sscanf(line, "%[^\t] %d %d %d %d %d", full_name, &size0, &cnt0, &total0, &size1, &cnt1);
			sscanf(full_name, "%[^\t\( ]", short_name);

			// for debugging
			// printf("'%s' '%s' size1=%d cnt1=%d\n", full_name, short_name, size1, cnt1);

			printf("{DDR_ID1, %-40s, %-7d, %-3d },\n", short_name, size1, cnt1);
		}
		printf("\n");
		fclose(fp);

		printf("{(HD_COMMON_MEM_DDR_ID)-1, -1, -1, -1}\n\n");
	}

	return 0;
}
