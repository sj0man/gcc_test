#include <stdio.h>
#include <string.h>


int main(void)
{
	char data[256]="1234567890abcdefghij1234567890123456789012345678901234567890";
	char tmp[256];
	char *p;
	int idx=0, kk=0;
	
	memset(tmp, 0, sizeof(tmp));
	for(kk=15; kk<strlen(data); kk++, idx++) {
		tmp[idx] = data[kk];
	}
	puts(data);
	puts(tmp);

	p = (char *)data+sizeof(char)*15;
	puts(p);
}

