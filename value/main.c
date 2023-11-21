#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>


#define VGA_TYPE	0x02
#define HDMI_TYPE	0x04

#define VOUT_IDX_MAIN	(0)
#define VOUT_IDX_SPOT	(1)
#define VOUT_IDX_HDSPOT	(2)

int func(short vout_idx)
{
#if 0
	if ((vout_idx > VOUT_IDX_MAIN && vout_idx < VOUT_IDX_HDSPOT) || (vout_idx < 0) ) {
		return -1;
	}
#else
	if (!((vout_idx == VOUT_IDX_MAIN) || (vout_idx == VOUT_IDX_HDSPOT))) {
		return -1;
	}
#endif

	printf("vout_idx = %d\n", vout_idx);
	return 0;
}

/*

*/
int main(int argc, char *argv[])
{
	int main_type = HDMI_TYPE;

	if(func(VOUT_IDX_MAIN) < 0) {
		printf("VOUT_IDX_MAIN error\n");
	}

	if(func(VOUT_IDX_SPOT) < 0) {
		printf("VOUT_IDX_SPOT error\n");
	}

	if(func(VOUT_IDX_HDSPOT) < 0) {
		printf("VOUT_IDX_HDSPOT error\n");
	}

	if(func(-1) < 0) {
		printf("-1 error\n");
	}
	if(func(3) < 0) {
		printf("3 error\n");
	}

	return 0;


	// 하나라도 포함되어 있으면 참
	if (main_type & (VGA_TYPE|HDMI_TYPE)) {
		printf("VGA_TYPE|HDMI_TYPE\n");
	} else {
		printf("not VGA_TYPE|HDMI_TYPE\n");
	}

	// 정확히 일치해야 참
	if (main_type == (VGA_TYPE|HDMI_TYPE)) {
		printf("VGA_TYPE|HDMI_TYPE\n");
	} else {
		printf("not VGA_TYPE|HDMI_TYPE\n");
	}

	return 0;
}