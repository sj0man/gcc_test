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

#define BASE_NUM	0x08
void test_operater(void)
{
	int data = 0xff;
	bool tf = false;


	tf = !!(data & BASE_NUM);				// 0 또는 1 값을 반환한다.
	printf("%s\n", tf ? "true" : "false");	// bool 값을 출력

	printf("%#x\n", !(data&BASE_NUM));		// 반환하는 값을 0 또는 1 이다.

}

int test_shift(void)
{
	int i;
	unsigned data = 0;

	for (i=0; i<16; i++) {
		data |= (1 << i);
		printf("%08x\n", data);
	}
	return 0;
}

int main(void)
{
	test_shift();
	return 0;

	printf("sizeof(u64):%ld\n", sizeof(u64));
	printf("sizeof(u32):%ld\n", sizeof(u32));
	gpio_set_output(22);

	print_bit(0x12340000);

	test_operater();
}
