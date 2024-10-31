#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#define MAX_COUNT		10
#define SIZE_DAL_TEXT	256

int print_info(char *src_str)
{
	int cnt = 0;
	char *src_ptr = src_str;

	while(1) {
		if (strlen(src_ptr) == 0) {
			break;
		}
		printf("%d: %s\n", cnt, src_ptr);
		cnt++;
		src_ptr += strlen(src_ptr) + 1;
	}
	puts("--------------------");

	return 0;
}

int set_info(char *src_str, const char *filter, const char *result)
{
	int cnt = 0;
	char *dst_str = (char *)calloc(SIZE_DAL_TEXT, sizeof(char));
	char *dst_ptr = dst_str;
	char *src_ptr = src_str;
	int len = SIZE_DAL_TEXT;

	while(1) {
		if (strlen(src_ptr) == 0) {
			break;
		}
		if (strncmp(src_ptr, filter, strlen(filter)) == 0) {
			strncpy(dst_ptr, result, strlen(result));
		}
		else {
			strncpy(dst_ptr, src_ptr, len);
		}
		// printf("%d: src_ptr: %s -----> dst_ptr: %s\n", cnt, src_ptr, dst_ptr);
		cnt++;
		len -= strlen(src_ptr);
		src_ptr += strlen(src_ptr) + 1;
		dst_ptr += strlen(dst_ptr) + 1;
	}
	// printf("dst_str: %p, dst_ptr: %p\n", dst_str, dst_ptr);
	dst_ptr[SIZE_DAL_TEXT - 1] = '\0';

	memcpy(src_str, dst_str, SIZE_DAL_TEXT);
	free(dst_str);

	return 0;
}

int main(void)
{
	char src_str[SIZE_DAL_TEXT] = {
		"ipaddr=192.168.0.91\0"
		"serverip=192.168.0.11\0"
		"ethaddr=00:0c:29:3a:3b:3c\0"
		"gatewayip=192.168.0.91\0"
	};
	print_info(src_str);
	set_info(src_str, "ethaddr", "ethaddr=00:11:22:33:44:55");
	print_info(src_str);

	return 0;
}