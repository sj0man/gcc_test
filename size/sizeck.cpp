// hexa file size
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sys/stat.h"


const char *number2comma(size_t n)
{
    static char comma_str[64];
    char   str[64];
    int    idx, len, cidx = 0, mod;
    
    sprintf(str, "%ld", n);
    len = strlen(str);
    mod = len % 3;
    
    for(idx = 0; idx < len; idx++) {
        if(idx != 0 && (idx) % 3 == mod) {
            comma_str[cidx++] = ',';
        }
        comma_str[cidx++] = str[idx];
    }
    
    comma_str[cidx] = 0x00;
    return comma_str;
}

static size_t get_file_size (const char * file_name)
{
	int errno=0;
	struct stat sb;

	if ((errno=stat(file_name, & sb)) != 0) {
		fprintf(stderr, "'stat' failed for '%s': %s.\n", file_name, strerror (errno));
		exit(EXIT_FAILURE);
	}
	return sb.st_size;
}

int main (int argc, char ** argv)
{
	int i, len, maxlen=0;
	const char * file_name;
	size_t size;

	if(argc < 2) {
		printf("Usage: %s filename\n\n", basename(argv[0]));
		return -1;
	}

	for(i=1; i<argc; i++) {		
		file_name = argv[i];
		len = strlen(file_name);
		if(len > maxlen)
			maxlen = len;
	}

	for(i=1; i<argc; i++) {
		file_name = argv[i];
		size = get_file_size(file_name);
		printf("%*s: %12s %#lx\n", maxlen, file_name, number2comma(size), size);
	}
	printf("\n");
	return 0;
}
