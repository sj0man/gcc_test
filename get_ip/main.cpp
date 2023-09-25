#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#define FNAME   "tmp.txt"
#define MAX_CHAR	256

#define MAX_IPADDR_LEN		40
#include <sys/ioctl.h>
#include <net/if.h>
#include <arpa/inet.h>

int _get_eth1_ip(char *eth1_ip)
{
	struct ifreq ifr;
	char ipstr[40];
	int s;

	s = socket(AF_INET, SOCK_DGRAM, 0);
	strncpy(ifr.ifr_name, "enp0s3", IFNAMSIZ);
	// strncpy(ifr.ifr_name, "eth0", IFNAMSIZ);

	if (ioctl(s, SIOCGIFADDR, &ifr) < 0) {
		return -1;
	} else {
		inet_ntop(AF_INET, ifr.ifr_addr.sa_data+2, ipstr,sizeof(struct sockaddr));
		strncpy(eth1_ip, ipstr, sizeof(ipstr));
		printf("myOwn IP Address is %s\n", ipstr);
	}

	return 0;
}

int main()
{
	int ret;
	char eth1_ip[40];

	ret = _get_eth1_ip(eth1_ip);
	printf("ret = %d\n", ret);

	return 0;
}

