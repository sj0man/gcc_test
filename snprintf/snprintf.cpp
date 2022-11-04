/* snprintf example */
#include <stdio.h>

int test1()
{
	int len;
	char data[256];


	len = snprintf(data, sizeof(data), "%.*s", 6, "I love South Korea.");
	printf("data=\"%s\"\n", data);
}

int main ()
{
	char buffer [100];
	int cx;


	printf("num=0x%02x\n", 9);
	test1();
	return 0;

	cx = snprintf ( buffer, 100, "The half of %d is %d", 60, 60/2 );

	if (cx>=0 && cx<100)		// check returned value

		snprintf ( buffer+cx, 100-cx, ", and the half of that is %d.", 60/2/2 );

	puts (buffer);

	return 0;
}

