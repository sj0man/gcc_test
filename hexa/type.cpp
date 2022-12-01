#include <stdio.h>

typedef enum {
	VOUT_LAYOUT_NONE = 0,
	VOUT_LAYOUT_1x1,
	VOUT_LAYOUT_2x2,
	VOUT_LAYOUT_3x2,
	VOUT_LAYOUT_3x3,
	VOUT_LAYOUT_3x3_1,	// 1 ==> 2x2
	VOUT_LAYOUT_4x3,
	VOUT_LAYOUT_4x3_1,	// 2 ==> 2x2
	VOUT_LAYOUT_4x3_2,	// 1 ==> 2x2
	VOUT_LAYOUT_4x4,
	VOUT_LAYOUT_4x4_1,	// 1 ==> 2x2
	VOUT_LAYOUT_4x4_2,	// 1 ==> 3x3
	VOUT_LAYOUT_5x4,
	VOUT_LAYOUT_5x4_1,	// 1 ==> 3x3
	VOUT_LAYOUT_5x4_2,	// 2 ==> 2x2
	VOUT_LAYOUT_5x4_3,	// 1 ==> 2x2
	VOUT_LAYOUT_5x5,
	VOUT_LAYOUT_5x5_1,	// 1 ==> 2x2
	VOUT_LAYOUT_5x5_2,	// 1 ==> 3x3
	VOUT_LAYOUT_6x6,
	VOUT_LAYOUT_6x6_1,	// 1 ==> 2x2
	VOUT_LAYOUT_6x6_2,	// 1 ==> 3x3
	VOUT_LAYOUT_7x5,
	MAX_VOUT_LAYOUT
} VOUT_LAYOUT_T;

int func(VOUT_LAYOUT_T layout)
{
    printf("%d", layout);
}

int main(void)
{
    VOUT_LAYOUT_T layout = VOUT_LAYOUT_3x3;
    func(layout);
}