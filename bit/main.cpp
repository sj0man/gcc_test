#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <errno.h>
#include <dirent.h>
#include <unistd.h>

#define GET_VALUE(data, lbit, hbit) ((data >>lbit) & (~(~0<<(hbit-lbit+1))))

typedef unsigned int	u32;
typedef unsigned long   u64;


void print_bit(u32 data)
{
	printf("data:%#x\n", GET_VALUE(data, 16, 19));
}

static void gpio_set_output(u32 pin)
{
	u32 reg_data;

	pin &= (32 - 1);

	printf("0x%08x\n", 1<<pin);
	reg_data = 0x12340000;

	printf("0x%08x + 0x%08x = 0x%08x\n", reg_data, 1<<pin, reg_data|1<<pin);
}

int main(void)
{
	printf("sizeof(u64):%ld\n", sizeof(u64));
	printf("sizeof(u32):%ld\n", sizeof(u32));
	gpio_set_output(22);

	print_bit(0x12340000);
}
