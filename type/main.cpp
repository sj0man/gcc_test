#include <stdio.h>

int main(void)
{
    char a=-1, b=0x7f, c=0x80, d=0xff;

    printf("-1:%d, 0x7f:%d, 0x80:%d 0xff:%d\n", a, b, c, d);
    return 0;
}

/*

ARM계열은 char 일때 기본값은 unsigned char 이다.

*/