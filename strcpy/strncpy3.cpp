#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>


#define BOOKMARK_SIZE		32


int AddBookmark(char *nickname)
{
	char *textin = NULL;

	printf("sizeof(nickname): %ld strlen(nickname)+1: %d\n", sizeof(nickname), (int)strlen(nickname)+1);

	textin = (char *)malloc(strlen(nickname)+1);
	memset(textin, 0, BOOKMARK_SIZE+1);
	strncpy(textin, nickname, BOOKMARK_SIZE);

	printf("textin: %s nickname: %s\n", textin, nickname);

	return 0;
}


int main(void)
{
	char p[BOOKMARK_SIZE] = "1234567890123456";

	AddBookmark(p);
	return 0;
}