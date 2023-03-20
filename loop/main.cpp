#include <stdio.h>

unsigned char 	mylist[16384];


// ulaw 디코딩하기
#define QUANT_MASK  (0xf)	   /* Quantization field mask. */
#define BIAS		(0x84)	  /* Bias for linear code. */
#define SEG_SHIFT   (4)	 /* Left shift for segment number. */
#define SEG_MASK	(0x70)	  /* Segment field mask. */
#define SIGN_BIT	(0x80)	  /* Sign bit for a A-law byte. */

static int ulaw2linear(unsigned char   u_val)  
{
	int	 t;

	/* Complement to obtain normal u-law value. */
	u_val = ~u_val; 

	/*
	 * Extract and bias the quantization bits. Then
	 * shift up by the segment number and subtract out the bias.
	 */
	t = ((u_val & QUANT_MASK) << 3) + BIAS; 
	t <<= ((unsigned)u_val & SEG_MASK) >> SEG_SHIFT;

	return ((u_val & SIGN_BIT) ? (BIAS - t) : (t - BIAS)); 
}

static void build_xlaw_table(unsigned char *linear_to_xlaw,
		int (*xlaw2linear)(unsigned char),
		int mask)
{
	int i, j, v, v1, v2;

	j = 0;
	for(i=0;i<128;i++) {
		if(i>=128) {
			printf("128\n");
			break;
		}
		if (i != 127) {
			v1 = xlaw2linear(i ^ mask);
			v2 = xlaw2linear((i + 1) ^ mask);
			v = (v1 + v2 + 4) >> 3;
		} else {
			v = 8192;
		}
		printf("i:%d, j:%d, v:%d, v1:%d, v2:%d\n", i,j,v,v1,v2);
		for(;j<v;j++) {
			linear_to_xlaw[8192 + j] = (i ^ mask);
			if (j > 0)
				linear_to_xlaw[8192 - j] = (i ^ (mask ^ 0x80));
		}
		printf("\t\t i:%d, j:%d, v:%d, v1:%d, v2:%d\n", i,j,v,v1,v2);
	}
	linear_to_xlaw[0] = linear_to_xlaw[1];
	return;
}

int build_ulaw_table(unsigned char *linear2ulaw)
{
	build_xlaw_table(linear2ulaw, ulaw2linear, 0xff);
	return 0;
}

int main(void)
{
	build_ulaw_table(mylist);
	return 0;
}
