#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#define MAX_CHAR	(256)
#define MAX_DDR		(4)
#define MAX_TYPE	(30)

char _name[MAX_TYPE][MAX_CHAR];
int _size[MAX_DDR][MAX_TYPE];
int _cnt[MAX_DDR][MAX_TYPE];


int print_ddr(int array_index, int ddr_index)
{
	int i;
	char short_name[MAX_CHAR];

	sprintf(short_name, "%s%d", "DDR_ID", ddr_index);
	for (i=0; i<MAX_TYPE; i++) {
		if (_size[array_index][i] == 0 || _cnt[array_index][i] == 0) {
			printf("//\t{%s, %-40s, %-7d, %-3d},\n", short_name, _name[i], _size[array_index][i], _cnt[array_index][i]);
		}
		else {
			printf("\t{%s, %-40s, %-7d, %-3d},\n", short_name, _name[i], _size[array_index][i], _cnt[array_index][i]);
		}
	}
	printf("\n");

	return 0;
}

int main(int argc, char *argv[])
{
	FILE *fp = NULL;
	char *fname = NULL;
	char line[MAX_CHAR];
	char full_name[MAX_CHAR];
	char short_name[MAX_CHAR];
	int size0, cnt0, total0;
	int size1, cnt1, total1;
	int size2, cnt2, total2;
	int size3, cnt3, total3;
	int idx = 0;
	int i;

	if (argc != 2) {
		printf("Usage: %s <file>\n\n", argv[0]);
		return -1;
	}

	fname = argv[1];
	if((fp = fopen(fname, "r")) == NULL) {
		printf("Error: fopen(%s) failed: %s\n", fname, strerror(errno));
		return -1;
	}

	while (fgets(line, sizeof(line), fp)) {
		size0 = cnt0 = total0 = 0;
		size1 = cnt1 = total1 = 0;
		size2 = cnt2 = total2 = 0;
		size3 = cnt3 = total3 = 0;
		sscanf(line, "%[^\t] %d %d %d %d %d %d %d %d %d %d %d %d", full_name,
			&size0, &cnt0, &total0, &size1, &cnt1, &total1, &size2, &cnt2, &total2, &size3, &cnt3, &total3);
		sscanf(full_name, "%[^\t\( ]", short_name);

		strcpy(_name[idx], short_name);
		_size[0][idx] = size0;
		_size[1][idx] = size1;
		_size[2][idx] = size2;
		_size[3][idx] = size3;
		_cnt[0][idx] = cnt0;
		_cnt[1][idx] = cnt1;
		_cnt[2][idx] = cnt2;
		_cnt[3][idx] = cnt3;

		// for debugging
		// printf("full_name='%s' short_name='%s'\n", full_name, short_name);
		// printf("%2d: %-40s,%-7d,%-3d,%-7d,%-3d,%-7d,%-3d,%-7d,%-3d\n",
		// 	idx+1, _name[idx], _size[0][idx], _cnt[0][idx], _size[1][idx], _cnt[1][idx], _size[2][idx], _cnt[2][idx], _size[3][idx], _cnt[3][idx]);
		idx++;
	}
	fclose(fp);


	for (i=0; i<4; i++) {
		print_ddr(i, i);
	}
	print_ddr(2, 4);
	print_ddr(3, 5);
	print_ddr(2, 6);
	print_ddr(3, 7);

	printf("\t{(HD_COMMON_MEM_DDR_ID)-1, -1, -1, -1}\n\n");

	return 0;
}
