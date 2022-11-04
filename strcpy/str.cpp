#include <stdio.h>
#include <string.h>

int f(char *p)
{
	int tlen=0;
	char *start, *end;
	char data[256];

	// memset(data, 0, sizeof(data));
	start = strstr(p, "love");
	end = strstr(p, ".");

	tlen = end - start;
	memcpy(data, start, tlen);
	data[tlen] = 0; // 배열 전체로 0으로 채우지 않았다면 문자열 마지막에 0을 넣어줘야 한다.
	printf("data=\"%s\"\n", data);
}

int main(void)
{
	char data[256]="I love Seoul.";
	char tmp[256];
	char *p;
	int idx=0, kk=0;
	
	f(data);
	return 0;

	memset(tmp, 0, sizeof(tmp));
	for(kk=3; kk<strlen(data); kk++, idx++) {
		tmp[idx] = data[kk];
	}
	puts(data);
	puts(tmp);

	p = (char *)data+sizeof(char)*3;
	puts(p);
}

