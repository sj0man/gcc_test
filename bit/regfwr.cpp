#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <errno.h>
#include <dirent.h>
#include <unistd.h>
#include "sys/types.h"
#include "regex.h"

int main(int argc, char *argv[])
{
	regex_t state;
	const char *urls[] = {
		"3.12.0.10A",
		"3.1.3.b",
		"3.10.0.1",
	};
	const char *pattern = "^[1-9][0-9]*\\.[0-9]+\\.[0-9]+\\.[0-9]+[A-Za-z]$";
	// const char *pattern = "^[1-9][0-9]*\.[0-9]+\.[0-9]+\.[0-9]+[A-Za-z]$";
	// const char *pattern = "^[1-9][0-9]*.[0-9]+.[0-9]+.[0-9]+[A-Za-z]$";


	int index;
	//compile
	regcomp(&state, pattern, REG_EXTENDED);

	puts(pattern);
	for (index = 0; index < 3; index++) {
		//check
		int status = regexec(&state, urls[index], 0, NULL, 0);
		if(status==0)
			printf("match : %s\n", urls[index]);
		else
			printf("unmatch : %s\n", urls[index]);
	}

	return 0;
}
