#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>


#define MAX_NUM		10

#if 1

int main(int argc, char *argv[])
{
	int i;
	unsigned int id[MAX_NUM] = {
		0x3100,
		0x3140,
		0x3701,
		0x3100,
		0x3100,
		0x3100,
		0x3140,
		0x3701,
		0x3100,
		0x3100,
	};

	for (i=0; i<MAX_NUM; i++) {
		if (id[i] & 0x00f0) {
			printf("\t\t Unexpected chip id\n");
			printf("\t\t i:%d tid:0x%04x\n", i, id[i]);
			id[i] &= 0xff0f;
		}

		printf("id[%d] = 0x%04x\n", i, id[i]);
	}

	return 0;
}

#else
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

#endif