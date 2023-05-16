#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#define FNAME   "tmp.txt"
#define MAX_CHAR	256

#define MAX_DEV		8
unsigned int en33x_dev_id[] = {
	0xbc, 0xb4, 0x8c, 0x84, 0xac, 0xa4, 0x9c, 0x94,
};


int func(unsigned short devaddr, unsigned short regaddr)
{
	unsigned short i2c_addr;
	unsigned short page_data;

    i2c_addr = regaddr << 2;
	page_data = i2c_addr >> 8;
	i2c_addr = i2c_addr & 0xff;

	printf("devaddr=%#x\t", devaddr);
	printf("page_data=%#x\t", page_data);
	printf("i2c_addr=%#x\n", i2c_addr);


	return 0;
}

int main(void)
{
	int i;
	for(i=0; i<MAX_DEV; i++) {
		func(en33x_dev_id[i], 0xeee);
	}

}
