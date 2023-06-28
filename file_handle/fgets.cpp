#include <stdio.h>
#include <stdlib.h> // system
#include <string.h>
#include <errno.h>
#include <fcntl.h>  // open
#include <unistd.h> // write, fsync, close

#define SIZE_DAL_TEXT   256


int main(void)
{
	FILE	*fp;
	char	szbuf[SIZE_DAL_TEXT];
	int		l_gw_eth[4] = {0, 0, 0, 0};
	int		cnt = 0;

	strncpy(szbuf, "/proc/net/route", sizeof(szbuf));
	szbuf[sizeof(szbuf) - 1] = '\0';

	if ((fp = fopen(szbuf, "rt")) == NULL) {
		printf("fopen(szbuf=\"%s\",...) fail! errno=%d,\"%s\"\n", szbuf, errno, strerror(errno));
	}
	else {
		while (fgets(szbuf, sizeof(szbuf), fp) != NULL) {
			if (strstr(szbuf, "enp0s3") && strstr(szbuf, "0003")) {
				printf("szbuf=%s", szbuf + 16);
				int ip0, ip1, ip2, ip3;
				ip0 = ip1 = ip2 = ip3 = 0;

				cnt = sscanf(szbuf + 16, "%02X%02X%02X%02X", &ip3, &ip2, &ip1, &ip0);
				if (cnt != 4) {
					printf("szbuf does not have required string! cnt=%d szbuf+14=\"%s\"\n", cnt, szbuf + 14);
				}

				l_gw_eth[0] = ip0;
				l_gw_eth[1] = ip1;
				l_gw_eth[2] = ip2;
				l_gw_eth[3] = ip3;
				// break;
			}
		}
	}
	printf("%d.%d.%d.%d\n", l_gw_eth[0], l_gw_eth[1], l_gw_eth[2], l_gw_eth[3]);
	return 0;
}