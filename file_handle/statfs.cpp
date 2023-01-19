#include <stdio.h>
// #include <sys/vfs.h>
#include <sys/statfs.h>
#include <linux/magic.h>

// /usr/include/linux/magic.h

#define FNAME   "main.cpp"

int main(void)
{
	struct statfs fsinfo;
	
	if (statfs(FNAME, &fsinfo) == 0) {
		puts("ok");
		printf("f_type=0x%08lx\n", fsinfo.f_type);
	} else {
		puts("fail");
	}

}