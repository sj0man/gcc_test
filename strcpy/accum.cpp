#include <stdio.h>
#include <string.h>

#define MAX_NUM		10
int num[MAX_NUM] = {
	10,
	-1,
	10002,
	13,
	14,
	1005,
	16,
	-107,
	18,
	19
};

#define MAX_CHAR	256
char buf[MAX_CHAR];

int main(void)
{
	int	i;
	char tmp[MAX_CHAR];

	// initial
	memset(buf, 0, sizeof(buf));

	for (i=0; i<MAX_NUM; i++) {
		snprintf(tmp, sizeof(tmp), "(%d,%d) ", i, num[i]);
		strcat(buf, tmp);
	}
	printf("%s\n", buf);

	return 0;
}

