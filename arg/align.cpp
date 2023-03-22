#include <stdio.h>
#include <stdlib.h>

#define ALIGN_FLOOR(value, base)  ((value) & ~((base)-1))                   ///< Align Floor
#define ALIGN_ROUND(value, base)  ALIGN_FLOOR((value) + ((base)/2), base)   ///< Align Round
#define ALIGN_CEIL(value, base)   ALIGN_FLOOR((value) + ((base)-1), base)   ///< Align Ceil



int main(int argc, char *argv[])
{
	unsigned long value = 0x123;
	if(argc == 2) {
		value = strtol(argv[1], NULL, 16);
	}

	printf("0x%08lx\n", ALIGN_CEIL(value, 256));
}
