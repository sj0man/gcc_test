#include <stdio.h>

#define START 	8
#define END 	13

int main(void)
{
	int i;


	for(i=START; i<END; i++) {
		printf("[%2d]\n", i);
	}
	for(i=START; i<END; i++) {
		printf("[%3d]\n", i);
	}

	for(i=START; i<END; i++) {
		printf("[% 2d]\n", i);
	}

	for(i=START; i<END; i++) {
		printf("[% 3d]\n", i);
	}

	for(i=START; i<END; i++) {
		printf("[%-2d]\n", i);
	}

	for(i=START; i<END; i++) {
		printf("[%-3d]\n", i);
	}

	return 0;
}
