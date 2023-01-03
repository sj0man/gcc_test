#include "sub.h"


int main()
{
    int a = 1;
    int b = 2;
    int c = 3;

    func();
    func(a);
    func(a, b);
    func(a, b, c);

    return 0;
}