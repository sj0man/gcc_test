#include <stdio.h>
#include <string.h>
// system() function call
#include <stdlib.h>


#define DIR		"./tmp"
#define FILE	"list"

int main(void)
{
	char data[256]=DIR "/" FILE;
	char szcmd[256]="";

	sprintf(szcmd, "mkdir -p %s", DIR);
	if(system(szcmd) != 0) {
		printf("can't make directory.\n");
		return -1;
	}

	puts(data);
	sprintf(szcmd, "touch %s", data);
	system(szcmd);

	sprintf(szcmd, "ls -lF %s", data);
	system(szcmd);

	sprintf(szcmd, "rm %s", data);
	system(szcmd);

	sprintf(szcmd, "rmdir %s", DIR);
	if(system(szcmd) != 0) {
		printf("can't remove directory.\n");
		return -2;
	}

	return 0;
}

