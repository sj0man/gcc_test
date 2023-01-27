#include <stdio.h>


#define DPRINTF(_x_)  { \
	printf("%-20s(%4d)> ", __FUNCTION__, __LINE__);	\
	printf _x_	;\
	fflush(stdout);}

#if 0
#undef DBG
#define DBG(x)
#else
#define DBG     DPRINTF
#endif

#define LOG		DPRINTF


int func(int idx)
{
    int i;

    DBG(("idx:%d\n", idx));

    for (i=0; i<idx; i++) {
        printf("%3d\n", i);
    }

    return 0;
}

int main(void)
{
    func(10);

    return 0;
}
