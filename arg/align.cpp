#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ALIGN_FLOOR(value, base)  ((value) & ~((base)-1))                   ///< Align Floor
#define ALIGN_ROUND(value, base)  ALIGN_FLOOR((value) + ((base)/2), base)   ///< Align Round
#define ALIGN_CEIL(value, base)   ALIGN_FLOOR((value) + ((base)-1), base)   ///< Align Ceil


#if 0
int main(int argc, char *argv[])
{
	unsigned long value = 0x123;
	if(argc == 2) {
		value = strtol(argv[1], NULL, 16);
	}

	printf("0x%08lx\n", ALIGN_CEIL(value, 256));
}

#else

int main(int argc, char *argv[])
{
	int i;
	int fdaemon = 0;

	printf("argv[0]=\'%s\' argc=%d\n", argv[0], argc);
	for (i=1; i<argc; i++) {
		if (strstr(argv[i], "-daemon")) {
			fdaemon = 1;
			break;
		}
	}

	if (fdaemon) {
		printf("daemon\n");
	}
	else {
		printf("no daemon\n");
	}

	return 0;
}

#endif
