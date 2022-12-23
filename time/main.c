/*****
 * time.h
	asctime() — 시간을 문자 스트링으로 변환
	asctime_r() — 시간을 문자 스트링으로 변환(재시작 가능)
	ctime() — 시간을 문자 스트링으로 변환
	ctime_r() — 시간을 문자 스트링으로 변환(재시작 가능)
	gmtime() — 변환 시간
	gmtime_r() — 변환 시간(다시 시작 가능)
	localtime() — 변환 시간
	mktime() — 로컬 시간 변환
	time() — 현재 시간 판별
*****/
#include <stdio.h>
#include <time.h>


int main()
{
	time_t mytt, mytt2;
	struct tm mytm, *p_tm;
	char buf[50];

	mytt = time(NULL);
	localtime_r(&mytt, &mytm);
	printf("time_t=%lu, %s\n", mytt, asctime_r(&mytm, buf));


	mytt2 = time(NULL);
	p_tm = localtime(&mytt2);
	printf("time_t=%lu, %s\n", mytt2, asctime(p_tm));


	return 0;
}