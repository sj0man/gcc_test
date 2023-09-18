#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#define FNAME   "tmp.txt"
#define MAX_CHAR	256



int file_write(FILE *fp, int cnt)
{
	char buf[MAX_CHAR];

	if((fp = fopen(FNAME, "a")) == NULL) {
		fprintf(stderr, "failed: %s\n", strerror(errno));
		return 1;
	}

	snprintf(buf, sizeof(buf), "%d: Hello World!\n", cnt);

	if (fputs(buf, fp) == 0) {
		fprintf(stderr, "failed: %s\n", strerror(errno));
	} else {
		printf("%s", buf);
	}

	fclose(fp);

	return 0;
}


/*
	파일을 하나로 특정할 수 있다면 stat 함수 활용
	파일을 특정할 수 없다면 ls -a 명령어 활용
	파일명 글자 수 주의
*/
int main(int argc, char *argv[])
{
	int ret = system("ls -a /tmp/.[A-Za-z]");	// 점으로 시작해서 한 글자인 파일명 출력
	// int ret = system("ls -a /tmp/.[A-Za-z]?");	// 점으로 시작해서 두 글자인 파일명 출력
	// int ret = system("ls -a /tmp/.?");		// .. 상위 디렉토리를 포함한 파일명 출력

	// 파일이 없으면 512 반환
	printf("ret = %d\n", ret);

	return 0;
}
