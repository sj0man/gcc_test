#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <errno.h>
#include <dirent.h>
#include <unistd.h>


#define CMD		"grep"
#define REGEXP	"\"[1-9][0-9]\\{1,2\\}\\.[0-9]\\{1,3\\}\\.[0-9]\\{1,3\\}\\.[0-9]\\{1,3\\}\""
#define HOSTS	"/etc/hosts"

int main(void)
{
	char szcmd[256];

	if(system("echo hi")) {
		puts("system failed.");
		exit(1);
	}

	sprintf(szcmd, "%s %s %s", CMD, REGEXP, HOSTS);
	puts(szcmd);
	if(system(szcmd)) {
		puts("system failed.");
		exit(1);
	}
}
