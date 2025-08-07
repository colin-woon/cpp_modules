#include <iostream>
#include <bitset>
#include <cstring>

void dump_64bits_double(double const d)
{
	uint64_t u;
	std::memcpy(&u, &d, sizeof(double));
	std::bitset<64> bits(u);
	std::cout << bits << std::endl;
}

void dump_32bits_integer(int const n)
{
	std::bitset<32> bits(n);
	std::cout << bits << std::endl;
}

// Implicit = automatic
// Explicit = on purpose
// -Wno-conversion flag will stop Implicit Demotions (but need to check c++ version)

// Classes have hiearchy too and cant be simply casted
// Child is more accurate than parent
// Child -> Parent - Upcast
// Parent -> Child - Downcast (will cause issues, child might have more different stuff)
// Child1 -> Child2 - also might cause issues cause we dont know their difference in implementation
class Parent
{
};
class Child1 : public Parent
{
};
class Child2 : public Parent
{
};

int main(void)
{
	int a = 42;

	double b = a;		  // Implicit Conversion
	double c = (double)a; // Explicit Conversion

	double d = a;	// Implicit Promotion -> OK
	int e = d;		// Implicit Demotion -> NOT OK!, loses accuracy
	int f = (int)d; // Explicit Demotion -> OK because you tell the compiler youre aware of the accuracy loss

	dump_32bits_integer(a);
	dump_64bits_double(b);
	dump_64bits_double(c);
	dump_64bits_double(d);

	dump_32bits_integer(e);
	dump_32bits_integer(f);

	// Child1 g;
	// Parent *h = &g;	// Ok
	// // Child1 *i = h;
	// Child2 *j = (Child2 *)i;
}
