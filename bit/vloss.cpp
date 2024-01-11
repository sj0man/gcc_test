#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <errno.h>
#include <dirent.h>
#include <unistd.h>
#include "sys/types.h"
#include "regex.h"


int gloss = 0xf7;

int _main(int vloss)
{
	int i;
	int old_vl;
	int new_vl;
	int value = 0;

	for (i=0; i<8; i++) {
		old_vl = (gloss & (1 << i));
		new_vl = (vloss & (1 << i));
		printf("i:%-2d old_vl:%#x, new_vl:%#x\n", i, old_vl, new_vl);
		if (old_vl != new_vl) {
			printf("vloss changed: %d -> %d\n", old_vl, new_vl);
		}
		else {
			value |= old_vl;
		}
	}

	return value;
}

int main(int argc, char *argv[])
{
	int data = 0xff;
	int value;

	value = _main(data);

	printf("value = %#x\n", value);

	return 0;
}
