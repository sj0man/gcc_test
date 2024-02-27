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


int main(int argc, char *argv[])
{
	int cam;

	for (cam=0; cam<32; cam++) {
		printf("cam:%2d, HD_VIDEOCAP_IN:%#x HD_VIDEOCAP_OUT:%#x\n", cam, HD_VIDEOCAP_IN(cam, 0), HD_VIDEOCAP_OUT(cam, 1));
	}

	return 0;
}

