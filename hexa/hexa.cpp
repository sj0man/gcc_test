#include <stdio.h>
#include <string.h>

#define MAX 8

int main(void)
{
	char data[256];
	// int cam[MAX] = {0,1,2,3,4,5,6,7};
	int cam[MAX] = {0,1,2,-1,-1,5,6,7};
	int i;
	unsigned int used = 0x0;

	memset(data, 0, sizeof(data));



	for (i=0; i<MAX; i++) {
		printf("% 2d\n", i);
		printf("%02d\n", i);	
	}

	return 0;


	printf("\"");
	for (i=0; i<MAX; i++) {
		printf("cam[%d]=%%d, ", i);
	}
	printf("\\n\"\n");

	for (i=0; i<MAX; i++) {
		printf("cam[%d], ", i);
	}
	printf("\n");


	return 0;

	for (i=0; i<MAX; i++){
		if(cam[i] < 0)
			continue;
		if(cam[i] >= 0) {
			 if(used & (0x1U << cam[i])) {
				cam[i] = -1;
			 } else {
				used |= (0x1U << cam[i]);
			 }
		}		
		printf("cam[%d]=%d, 0x%08x, used=0x%08x\n", i, cam[i], (0x1U << cam[i]), used);
	}
}