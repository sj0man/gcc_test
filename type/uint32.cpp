#include <stdio.h>
#include <stdlib.h>

typedef unsigned int    UINT32;

typedef UINT32      HD_PATH_ID;

int main(int argc, char *argv[])
{
    HD_PATH_ID path_id = 0xffffffff;

    if (path_id == -1)
        puts("same");
}
