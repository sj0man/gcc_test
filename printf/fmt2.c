// compile option -lm 추가해야 함.

#include <stdio.h>
#include <math.h>

int main(int argc, char **argv)
{
	int i;

	for(i=0; i<5; i++) {
		printf("[% *d]\n", i+4, (int)pow(10, i));
	}

	for(i=0; i<5; i++) {
		printf("[% -*d]\n", i+4, (int)pow(10, i));
	}

	return 0;
}

