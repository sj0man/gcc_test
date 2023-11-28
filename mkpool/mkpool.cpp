#include <stdio.h>

/*
	(1) copy data from excel to text

	(2) replace by regular expression
		^([^\t\( ]+)[^\t]*\t(\d{1,})\t(\d{1,})
		\t{ "\1", \2, \3 },

	(3) paste the replacement output into code.

	(4) compile and run

*/


struct fmt {
	char ss[100];
	int	n1;
	int	n2;
};


struct fmt data[] = {
	{ "HD_COMMON_MEM_COMMON_POOL", 22148, 1 },
	{ "HD_COMMON_MEM_DISP_DEC_IN_POOL", 32656, 1 },
	{ "HD_COMMON_MEM_DISP_DEC_OUT_POOL", 186792, 1 },
	{ "HD_COMMON_MEM_DISP_DEC_OUT_RATIO_POOL", 37968, 1 },
	{ "HD_COMMON_MEM_DEC_TILE_POOL", 6696, 1 },
	{ "HD_COMMON_MEM_ENC_CAP_OUT_POOL", 0, 0 },
	{ "HD_COMMON_MEM_ENC_OUT_POOL", 34240, 1 },
	{ "HD_COMMON_MEM_ENC_REF_POOL", 6072, 48 },
	{ "HD_COMMON_MEM_ENC_REF_POOL", 6072, 16 },
	{ "HD_COMMON_MEM_ENC_REF_POOL", 0, 0 },
	{ "HD_COMMON_MEM_ENC_REF_POOL", 0, 0 },
	{ "HD_COMMON_MEM_ENC_REF_POOL", 3244, 48 },
	{ "HD_COMMON_MEM_ENC_REF_POOL", 892, 16 },
	{ "HD_COMMON_MEM_ENC_SCL_OUT_POOL", 45596, 1 },
	{ "HD_COMMON_MEM_DISP0_CAP_OUT_POOL", 0, 0 },
	{ "HD_COMMON_MEM_DISP0_IN_POOL", 48600, 1 },
	{ "HD_COMMON_MEM_DISP0_FB_POOL", 8160, 1 },
	{ "HD_COMMON_MEM_DISP1_CAP_OUT_POOL", 0, 0 },
	{ "HD_COMMON_MEM_DISP1_IN_POOL", 12240, 1 },
	{ "HD_COMMON_MEM_DISP1_FB_POOL", 8160, 1 },
	{ "HD_COMMON_MEM_DISP2_CAP_OUT_POOL", 0, 0 },
	{ "HD_COMMON_MEM_DISP2_IN_POOL", 3240, 1 },
	{ "HD_COMMON_MEM_DISP2_FB_POOL", 812, 1 },
	{ "HD_COMMON_MEM_AU_ENC_AU_GRAB_OUT_POOL", 200, 1 },
	{ "HD_COMMON_MEM_AU_DEC_AU_RENDER_IN_POOL", 40, 1 },
	{ "HD_COMMON_MEM_GLOBAL_MD_POOL", 296, 0 },
	{ "HD_COMMON_MEM_TMNR_MOTION_POOL", 1024, 16 },
	{ "HD_COMMON_MEM_CNN_POOL", 40960, 1 },
	{ "HD_COMMON_MEM_OSG_POOL", 4096, 1 },
	{ "HD_COMMON_MEM_USER_BLK", 192816, 1 },
	{"",-1,-1},
};

int main(void)
{
	int i=0;
	while(data[i].n1 != -1) {
		printf("\t{DDR_ID0, %-40s, %-7d, %-3d },\n", data[i].ss, data[i].n1, data[i].n2);
		i++;
		if(i>30) break;
	}
	printf("\t{(HD_COMMON_MEM_DDR_ID)-1, -1, -1, -1}\n");

	return 0;
}
