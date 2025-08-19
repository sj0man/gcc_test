#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <ctype.h>  // isprint 함수 사용을 위해 필요

#define MAX_CHAR	256

const char *login_key = "3R Global, Inc.";

static int encrypt_xor(char *value, int vlen, char *key, char *retval)
{
	short unsigned int klen = strlen(key);
	short unsigned int k = 0;

	for (short unsigned int v = 0; v < vlen; v ++) {
		retval[v] = value[v] ^ key[k];
		k = (++ k < klen ? k : 0);
	}
	retval[vlen] = 0;

	return 0;
}



void print_mixed(const unsigned char *buf, int len) {
    for (int i = 0; i < len; i++) {
        if (isprint(buf[i])) {
            // 출력 가능한 아스키 문자(32~126)인 경우 그대로 출력
            printf("%c", buf[i]);
        } else if (buf[i] == 0) {
			// NULL 문자(0)는 특별히 \0 형태로 출력
			printf("\\0");
		} else if (buf[i] == '\n') {
			// 줄바꿈 문자는 \n 형태로 출력
			printf("\\n");
		} else if (buf[i] == '\r') {
			// 캐리지 리턴 문자는 \r 형태로 출력
			printf("\\r");
		} else if (buf[i] == '\t') {
			// 탭 문자는 \t 형태로 출력
			printf("\\t");
		} else if (buf[i] == '\v') {
			// 수직 탭 문자는 \v 형태로 출력
			printf("\\v");
		} else if (buf[i] == '\f') {
			// 폼 피드 문자는 \f 형태로 출력
			printf("\\f");
		} else if (buf[i] == '\a') {
			// 벨 문자(종소리)는 \a 형태로 출력
			printf("\\a");
		} else if (buf[i] == '\b') {
			// 백스페이스 문자는 \b 형태로 출력
			printf("\\b");
		} else if (buf[i] == '\0') {
			// NULL 문자(0)는 \0 형태로 출력
			printf("\\0");
		} else if (buf[i] == 0x1b) {
			// 이스케이프 문자(ESC)는 \e 형태로 출력
			printf("\\e");
		} else {
            // 그 외 값은 \x?? 형태로 출력
            printf("\\x%x", buf[i]);
        }
    }
    printf("\n");
}
/*

*/
int main(int argc, char *argv[])
{
	char buf[MAX_CHAR];

	memset(buf, 0, sizeof(buf));
	strcpy(buf, "qqwweerr1.");

	printf("Plain: %s\n", buf);
	encrypt_xor(buf, strlen(buf), (char *)login_key, buf);

	print_mixed((unsigned char *)buf, MAX_CHAR);
	return 0;
}
