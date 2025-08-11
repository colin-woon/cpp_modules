
// STATIC CAST
// ✅ The key technical advantage is compile - time safety.
// ❌ C - style casts can hide dangerous or unintended behavior, especially in large or old code.
// int *x = (int *)3.14; // will compile, even though it’s nonsense. It silently reinterprets a float as a pointer.
// int *x = static_cast<int *>(3.14); // ❌ Compile-time error

// Use DYNAMIC_CAST sparingly, when :
// 	You genuinely can’t know the type at compile time.
// 	The type affects behavior in ways polymorphism can’t express cleanly.
// 	You care about avoiding UB from a wrong static_cast.

// #include <iostream>
// #include <typeinfo>
// #include <exception>

// class Parent
// {
// public:
// 	virtual ~Parent(void) {};
// };
// class Child1 : public Parent
// {
// };
// class Child2 : public Parent
// {
// };

// int main(void)
// {
// 	Child1 a;
// 	Parent *b = &a;

// 	Child1 *c = dynamic_cast<Child1 *>(b);
// 	if (c == NULL)
// 		std::cout << "Conversion is NOT OK" << std::endl;
// 	else
// 		std::cout << "Conversion OK" << std::endl;

// 	try
// 	{
// 		Child2 &d = dynamic_cast<Child2 &>(*b);
// 		std::cout << "Conversion OK" << std::endl;
// 	}
// 	catch (const std::bad_cast &e)
// 	{
// 		std::cerr << "Conversion NOT OK " << e.what() << '\n';
// 	}
// }

// Use REINTERPRET_CAST only when you really have to.
// If you just need to convert within an inheritance hierarchy → use static_cast or dynamic_cast.
// If you need to convert between unrelated pointer types → reconsider your design before reaching for this.
// For low - level hacks only — Primarily used when dealing with :
// 	Legacy C APIs
// 	Raw memory buffers
// 	Hardware registers
// 	Serialization /deserialization
// This is implementation - defined — pointer and integer sizes must match, or you risk data loss.
// #include <iostream>
// int main()
// {
// 	int x = 42;
// 	int *ptr = &x;

// 	// Store the address as an integer
// 	long addr = reinterpret_cast<long>(ptr);

// 	// Recover the pointer from the integer
// 	int *samePtr = reinterpret_cast<int *>(addr);

// 	std::cout << *samePtr << "\n"; // 42
// }

// CONST_CAST IS USUALLY A BAD IDEA

// CAST OPERATORS, overwrites and directly handles the type assignment
#include <iostream>

class Foo
{
private:
	float _v;

public:
	Foo(float const v) : _v(v) {};

	float getV(void) { return this->_v; };

	operator float() { return this->_v; };
	operator int() { return static_cast<int>(this->_v); }
};

int main(void)
{
	Foo a(420.024f);
	float b = a;
	int c = a;

	std::cout << a.getV() << std::endl;
	std::cout << b << std::endl;
	std::cout << c << std::endl;
}
