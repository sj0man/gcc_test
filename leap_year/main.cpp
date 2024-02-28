#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>


#define START_YEAR 1582


int main(int argc, char *argv[])
{
	int year = 0;
	if(argc != 2) {
		printf("Usage: %s <year>\n", argv[0]);
		return 1;
	}
	else {
		year = strtol(argv[1], NULL, 10);
	}

	if (year < START_YEAR) {
		printf("Year must be greater than %d\n", START_YEAR);
		return 1;
	}

	if (year % 4 == 0) {
		if (year % 100 == 0) {
			if (year % 400 == 0) {
				printf("%d is a leap year\n", year);
			}
			else {
				printf("%d is not a leap year\n", year);
			}
		}
		else {
			printf("%d is a leap year\n", year);
		}
	}
	else {
		printf("%d is not a leap year\n", year);
	}

	return 0;
}