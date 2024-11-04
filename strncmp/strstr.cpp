
#include <stdio.h>
#include <string.h>

#define SIZE_DAL_TEXT	256

const char *szbuf = "KV_MODEL_NAME_INST04";

static int check_str(void)
{

	if (strstr(szbuf, "INST08") != NULL) {
		printf("INST04\n");
	}
	else {
		printf("NOT INST04\n");
	}

	return 0;
}

int main(void)
{
	check_str();

	return 0;
}

