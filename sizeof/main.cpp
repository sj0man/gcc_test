#include <stdio.h>


int main(void)
{
	printf("sizeof(char)=%ld\n", sizeof(char));
	printf("sizeof(short)=%ld\n", sizeof(short));
	printf("sizeof(int)=%ld\n", sizeof(int));
	printf("sizeof(long)=%ld\n", sizeof(long));
	printf("sizeof(long long)=%ld\n", sizeof(long long));

	puts("--");

	printf("sizeof(unsigned char)=%ld\n", sizeof(unsigned char));
	printf("sizeof(unsigned short)=%ld\n", sizeof(unsigned short));
	printf("sizeof(unsigned int)=%ld\n", sizeof(unsigned int));
	printf("sizeof(unsigned long)=%ld\n", sizeof(unsigned long));
	printf("sizeof(unsigned long long)=%ld\n", sizeof(unsigned long long));
}

