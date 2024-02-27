#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <errno.h>
#include <dirent.h>
#include <unistd.h>
#include "sys/types.h"
#include "regex.h"
#include "hd_type.h"
#include "hd_videoprocess.h"

static int ch2idx[32] = {
	28, 29, 30, 31,
	24, 25, 26, 27,
	12, 13, 14, 15,
	 8,  9, 10, 11,
	20, 21, 22, 23,
	16, 17, 18, 19,
	 4,  5,  6,  7,
	 0,  1,  2,  3
};


int main(int argc, char *argv[])
{
	int cam;
	int id;
	int chip;

	for (cam=0; cam<32; cam++) {
		chip = ch2idx[cam] / 8;
		id = ch2idx[cam] % 8;
		printf("cam:%2d id:%2d chip:%d HD_VIDEOPROC_CHIP_IN:%#x HD_VIDEOPROC_CHIP_OUT:%#x\n",
			cam, id, chip, HD_VIDEOPROC_CHIP_IN(chip, id, 0), HD_VIDEOPROC_CHIP_OUT(chip, id, 0));
	}

	return 0;
}

