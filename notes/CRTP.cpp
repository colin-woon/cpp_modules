#include <iostream>

class Base
{
public:
	typedef Base DerivedType; // Self-referencing typedef

	void interface()
	{
		static_cast<DerivedType *>(this)->implementation();
	}

	void implementation()
	{
		std::cout << "Base implementation\n";
	}
};

class Derived : public Base
{
public:
	typedef Derived DerivedType; // Override typedef

	void implementation()
	{
		std::cout << "Derived implementation\n";
	}
};

int main()
{
	Base b;
	Derived d;
	d.interface();		// Calls Derived::implementation()
	d.implementation(); // Calls Derived::implementation()
}
