#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>


#define MAX_NUM		10


int main(int argc, char *argv[])
{
	char *s;
	int a[MAX_NUM];
	int ret;

	s = getenv("SSH_CLIENT");
	ret = sscanf(s, "%d.%d.%d.%d %d %d", &a[0], &a[1], &a[2], &a[3], &a[4], &a[5]);

	printf("s = %s\n\n", s);
	for(int i = 0; i < ret; i++) {
		printf("a[%d] = %d\n", i, a[i]);
	}
	printf("ret = %d\n", ret);

	return 0;
}

