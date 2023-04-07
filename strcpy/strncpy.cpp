#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#define SIZE_DAL_TEXT	256


int ddl_get_info(char str[])
{
	int len;
	const char *info="3.02.113";

	len = strlen(info);
	printf("len:%d\n", len);
	memcpy(str, info, len);
	str[len] = 0;
	puts(str);
	return 0;
}

/*
 * strlen은 '\0' 제외한 길이를 반환, 따라서 마지막에 '\0' 문자를 복사하지 않는다.
 * 이에 대한 사전처리 (memset) 또는 후속 처리가 ('\0')가 필요하다.
 */
int main(void)
{
	int len;
	char dst_str[SIZE_DAL_TEXT];
#if 0
	char szdvrname[SIZE_DAL_TEXT] = "";

	memset(szdvrname, 0, sizeof(szdvrname));
	ddl_get_info(szdvrname);

	memset(dst_str, 0, sizeof(dst_str));

#else
	const char *szdvrname = "3.02.113";
#endif

	len = strlen(szdvrname);
	printf("len:%d\n", len);
#if 1
	strncpy(dst_str, szdvrname, len);
#else
	// strncpy(dst_str, szdvrname, len);
	memcpy(dst_str, szdvrname, len);
#endif

	// dst_str[len] = 0;
	puts(dst_str);
	return 0;
}