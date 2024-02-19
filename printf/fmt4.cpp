#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <errno.h>
#include <dirent.h>
#include <unistd.h>
#include "sys/types.h"
#include "regex.h"

#define MAX_NUM		(16)

int main(int argc, char *argv[])
{
	int i;

	for (i=0; i<MAX_NUM; i++) {
		printf("i:%-2d ch:%2d i:%2d\n", i, MAX_NUM-i, i);
	}

	return 0;
}
