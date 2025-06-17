#include <stdio.h>
#include <stddef.h>
#include <sys/statfs.h>
#include <inttypes.h>

struct statfs64	fs;
/*
    64bit 빌드 시
        size of long: 8
        sizeof(fs)=120,0x00000078

    32bit 빌드 시
        size of long: 4
        sizeof(fs)=84,0x00000054
 */
int main(void) {
    size_t size = sizeof(long);
    printf("size of long: %zu\n", size);

	printf("sizeof(fs)=%zu,0x%08" PRIx32 "\n", sizeof(fs), (uint32_t)sizeof(fs));

    return 0;
}

