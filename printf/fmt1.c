#include <stdio.h>

int main(int argc, char **argv)
{
	char str1[]	= "123456789012345678901234567890";
	int  width	= 0;

	//...

	width = 10;
	printf("[%.*s]\n", width, str1);

	width = 20;
	printf("[%.*s]\n", width, str1);

	return 0;
}
