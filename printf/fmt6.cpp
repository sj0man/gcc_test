#include <stdio.h>
#include <stddef.h>
#include <sys/statfs.h>
#include <inttypes.h>

#define MAX_CHAR	512

int main(void) {
	char buf[MAX_CHAR];
	char fmt[MAX_CHAR];

	sprintf(fmt, "%%.%ds", MAX_CHAR-1);
	puts(fmt);
	snprintf(buf, sizeof(buf), fmt, "Hello, World!");
	puts(buf);
	return 0;
}

