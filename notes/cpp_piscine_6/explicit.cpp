
// In the 90s / 2000s, implicit conversions were a common source of subtle bugs :
// 	Functions accidentally picking the wrong overload.
// 	Chained implicit conversions doing unexpected things.
// 	Performance hits from temporary object creation without realizing it.
#include <iostream>

class MyInt
{
	int value;

public:
	explicit MyInt(int v) : value(v) {}
	void print() { std::cout << value << "\n"; }
};

void doSomething(MyInt m)
{
	m.print();
}

int main()
{
	// doSomething(5); // ❌ Error: no implicit conversion
	doSomething(MyInt(5)); // ✅ Must be explicit
}
