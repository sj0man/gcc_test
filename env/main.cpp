#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#define FNAME   "tmp.txt"
#define MAX_CHAR	256

int temp(void)
{
	int ip0, ip1, ip2, ip3;
	int port1, port2;
	int cnt;
	const char *qwssize = NULL;

	ip0 = ip1 = ip2 = ip3 = 0;
	port1 = port2 = 0;
	if ((qwssize = ::getenv("SSH_CLIENT"))) {
		// puts(qwssize);
		cnt = sscanf(qwssize, "%d.%d.%d.%d %d %d", &ip0, &ip1, &ip2, &ip3, &port1, &port2);
		printf("cnt:%d, ip:%d.%d.%d.%d port1:%d, port2:%d\n", cnt, ip0, ip1, ip2, ip3, port1, port2);
	}
	return 0;
}


int main(void)
{
	temp();

	return 0;
}