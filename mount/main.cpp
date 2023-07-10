#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>


#define HOME_DIR		"/home"
#define TMP_DIR			"/tmp"
#define SIZE_DAL_TEXT	256


int func(char *path)
{
	char szdir[SIZE_DAL_TEXT];
	struct stat mountpoint;
	struct stat parent;

	/* Get the stat structure of the directory...*/
	sprintf(szdir, "%s", path);
	if (stat(szdir, &mountpoint) == -1) {
		printf("stat(%s) failed: %s\n", szdir, strerror(errno));
		return false;
	}

	/* ... and its parent. */
	sprintf(szdir, "%s/..", path);
	if (stat(szdir, &parent) == -1) {
		printf("stat(%s) failed: %s\n", szdir, strerror(errno));
		return false;
	}

	/* Compare the st_dev fields in the results:
		if they are equal, then both the directory and its parent belong to the
		 same filesystem, and so the directory is not currently a mount point.
	*/
	if (mountpoint.st_dev == parent.st_dev) {
		printf("Directory %s is not a mount point.\n", path);
	} else {
		printf("Directory %s is a mount point.\n", path);
	}

	return 0;
}

int main(void)
{
	func(HOME_DIR);
	func(TMP_DIR);

	return 0;
}