#include <stdio.h>

// Reintreperation in this context means reintrepreting the memory address to its real value
// Memory addresses switches = Identity Conversion = Reinterpretation.
// Type Qualifiers -- const, volatile, have this same issue too
int main()
{
	float a = 420.024f;

	void *b = &a;		  // Implicit reintrepretation cast
	void *c = (void *)&a; // Explicit reintrepretation cast

	void *d = &a;	   // Implicit Promotion -> OK
	int *e = d;		   // Implicit Demotion -> Misinterprets to another value
	int *f = (int *)d; // Explicit Demotion -> at least you told the compiler that you wanna do it liddat

	printf("%p, %f\n", &a, a);

	printf("%p\n", b);
	printf("%p\n", c);

	// Float -> void -> int will cause unexpected behaviours
	printf("%p\n", d);
	printf("%p, %d\n", e, *e);
	printf("%p, %d\n", f, *f);

	// Type Qualfiers
	int g = 42;

	int const *h = &g; // Promotion -> ok
	int *i = h;		   // Demotion -> not ok, will throw warning, const purpose is gone

	*i = 2;
	printf("%d", *i);
}
