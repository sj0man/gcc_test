#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

/*
	g++ 컴파일하면 에러 발생
	파일 확장자 cpp로 하면 컴파일 에러
	std=gnu11 옵션 추가하면 컴파일 에러 없음
*/
#define MAX_CHIPS	10
static int vout_mode[MAX_CHIPS] = {[0 ... (MAX_CHIPS - 1)] = 5};

int main(int argc, char *argv[])
{
	int i;

	for (i = 0; i < MAX_CHIPS; i++) {
		printf("vout_mode[%d] = %d\n", i, vout_mode[i]);
	}

	return 0;
}
