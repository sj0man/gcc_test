#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#define FNAME   "tmp.txt"
#define MAX_CHAR	256

#include "sub.cpp"

int bar(void)
{
	puts("bar");
	return 0;
}

/*

*/
int main(int argc, char *argv[])
{
	foo();
	bar();
	return 0;
}