#include <stdio.h>
#include "db.h"


int main(void)
{
    printf("head:%ld, date:%ld\n", sizeof(db6_head_t), sizeof(db6_date_t));

    return 0;
}

