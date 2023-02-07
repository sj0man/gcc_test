#include <stdio.h>

#define MAX_NUM     60

int main(void)
{
    char i = -1;

    printf("i:%d, max:%d\n", i, MAX_NUM);
    if (i >= 0 && i < MAX_NUM) {
        puts("1st ok");
    }

    if (i<0 || i>=MAX_NUM) {
        puts("2nd ok");
    }
    return 0;
}

/*

ARM계열은 char 일때 기본값은 unsigned char 이다.

*/