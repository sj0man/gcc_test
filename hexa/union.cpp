#include <stdio.h>

typedef struct
{
    int idx;
    union
    {
        int a;
        int b;
        int c;
    };    
} mytype;


int main(void)
{
    mytype var;

    printf("sizeof(mytype)=%ld\n", sizeof(mytype));
}