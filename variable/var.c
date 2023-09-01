#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>


#define MAX_X		5
#define MAX_Y		5
#define VALUE		0

#if 1

/*
	c포맷에서만 허용하는 syntax
	gcc 컴파일러와 파일 확장자를 .c 로 해야함.
	g++ 컴파일러 **또는** 파일 확장자를 .cpp 로 하면 에러 발생.
*/
int main(int argc, char *argv[])
{
	int i, j;
	int clk[MAX_X][MAX_Y] = {[0 ... (MAX_X - 1)][0 ... (MAX_Y - 1)] = VALUE};

	for(i=0; i<MAX_X; i++) {
		for(j=0; j<MAX_Y; j++) {
			printf("%d ", clk[i][j]);
		}
		printf("\n");
	}
}

#else

int main(int argc, char *argv[])
{
	int i, j;
	int clk[MAX_X][MAX_Y];

	// memset은 하위 한 바이트만 유효함 (0 or 0xff)
	memset(clk, VALUE, sizeof(clk));
	for(i=0; i<MAX_X; i++) {
		for(j=0; j<MAX_Y; j++) {
			printf("%d ", clk[i][j]);
		}
		printf("\n");
	}
}

#endif