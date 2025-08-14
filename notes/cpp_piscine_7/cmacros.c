// Preprocessing Macros

#include <stdio.h>

int max_int(int x, int y) { return (x >= y ? x : y); }

int foo(int x)
{
	printf("Long time\n");
	return x;
}

#define max(x, y) (((x) >= (y)) ? (x) : (y))

int main(void)
{
	int a = 21;
	int b = 42;

	printf("max int %d\n", max_int(foo(a), foo(b)));
	// (foo(b))) ? (foo(a)) : (foo(b))).
	// Because the condition is false, the expression after the colon : is evaluated : (foo(b)).foo(b) is called a second time, printing "Long time" again and returning 42.
	printf("max %d\n", max(foo(a), foo(b)));
}
