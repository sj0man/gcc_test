#include <stdio.h>
#include <stdlib.h>

#define SIZE_TXT	256
#define TMP_DIR		"/tmp"

int main(void)
{
	char sz_fwr[SIZE_TXT] = "fwr";
	char sz_file[SIZE_TXT] = "list2";
	char szcmd[SIZE_TXT*2];

	sprintf(szcmd, "tar -zxf %s -C %s ./%s", sz_fwr, TMP_DIR, sz_file);
	puts(szcmd);
	int r = system(szcmd);

	if (r != 0 && r != 512) {
		printf("error ret:%d\n", r);
		return -1;
	}

	printf("do next operation:%d.\n", r);

    return 0;
}