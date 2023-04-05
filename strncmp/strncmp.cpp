#include <stdio.h>
#include <string.h>

#define SIZE_DAL_TEXT	256

const char *szbuf = "udhcpc: lease of 192.168.0.50 obtained, lease time 604800";

const char *data2 = "udhcpc: Lease of";

static int check_dhcp(void)
{
	int ret;

	// ret = 1
	ret = strncmp(szbuf, "Lea of", strlen("Lease of"));
	printf("Lease of: %d\n", ret);


	// ret = 0
	ret = strncmp(szbuf, data2, strlen(data2));
	printf("%s: %d\n", data2 , ret);

	printf("%x, %x, diff:%d\n", 'l', 'L', (int)('l'-'L'));
	return 0;
}

#if 0
int main(void)
{
	check_dhcp();

	return 0;
}

#endif


#define  BUFF_SIZE   1024

int main(void)
{
	char  buff[BUFF_SIZE];
	FILE *fp;

	fp = popen( "route", "r");
	if (NULL == fp){
		perror( "popen() 실패");
		return -1;
	}
	while( fgets( buff, BUFF_SIZE, fp) )
		printf( "%s", buff);

	pclose(fp);

	return 0;
}

