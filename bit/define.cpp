#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <errno.h>
#include <dirent.h>
#include <unistd.h>
#include "sys/types.h"
#include "regex.h"


#define DDBG		printf

// 디버그 메시지 출력
#define DBG(x)		DDBG x

// 디버그 메시지 비출력
// #define DBG(x)




int main(int argc, char *argv[])
{
	int phydata = 0;

	DBG(("phydata = %d\n", phydata));

	return 0;
}
