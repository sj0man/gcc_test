#include <stdio.h>
#include <stdlib.h>
 
void func4(int a, int b) { printf("sum : %d\n", a + b); }
 
void func3(int a, int b) { return func4(a, b); }
 
void func2(int a, int b) { return func3(a, b); }
 
void func1(int a, int b) { return func2(a, b); }
 
int main(int argc, char *argv[])
{
	int a = atoi(argv[1]);
	int b = atoi(argv[2]);
 
	func1(a, b);
 
	return 0;
}

