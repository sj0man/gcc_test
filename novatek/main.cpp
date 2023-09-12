#include <stdio.h>

int main(void)
{
	char ch;

	printf("Enter value : ");
	ch  = getchar();

	printf("Enter value : 0x%02x\n", ch);

	return 0;
}
