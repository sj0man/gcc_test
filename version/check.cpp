#include <stdio.h>


int getVersion(char *szVer, int& major, int& minor, int& patch, int& build)
{
	sscanf(szVer, "%d.%d.%d.%d", &major, &minor, &patch, &build);
	return 0;
}

int main(void)
{
	char strVer[256] = "1.2.3.4";
	char strVer2[256] = "10.2.30.4";
	int major, minor, patch, build;

	major = minor = patch = build = -1;

	getVersion(strVer, major, minor, patch, build);
	printf("%d, %d, %d, %d\n", major, minor, patch, build);

	getVersion(strVer2, major, minor, patch, build);
	printf("%d, %d, %d, %d\n", major, minor, patch, build);

	return 0;
}