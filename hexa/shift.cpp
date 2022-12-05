#include <stdio.h>

#define MAX	8

int main(void)
{
	unsigned int used = 0x0U;
	int arr[MAX] = { -1, 1, 5, -1, 4, 2, 6, -1};
	int i;

	for (i=0; i<MAX; i++) {
		if (arr[i] < 0)
			continue;
		used |= (0x1U << arr[i]);
	}
	printf("used = 0x%08x\n", used);

	unsigned int flag = 0x1U;
	for (i=0; i<MAX; i++) {
		// printf("%d: used=0x%08x, flag=0x%08x\n", i, used, flag);
		if (!(used & flag)) {
			printf("%d: empty\n", i);
		}
		flag <<= 1; 
	}

	return 0;
}