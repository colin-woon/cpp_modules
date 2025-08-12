#include <iostream>
#include <cstdlib> // For rand() and srand()
#include <ctime>   // For time()

class Base
{
public:
	virtual ~Base() {}
};
class A : public Base
{
};
class B : public Base
{
};
class C : public Base
{
};

Base *generate(void)
{
	srand(time(NULL));
	int random = rand() % 3;

	switch (random)
	{
	case 0:
		return new A();
	case 1:
		return new B();
	case 2:
		return new C();
	default:
		return (NULL);
	}
}

// If dynamic cast fail, will return NULL
void identify(Base *p)
{
	if (dynamic_cast<A *>(p))
		std::cout << "A identified" << std::endl;
	else if (dynamic_cast<B *>(p))
		std::cout << "B identified" << std::endl;
	else if (dynamic_cast<C *>(p))
		std::cout << "C identified" << std::endl;
}

// If dynamic cast fail, will throw a bad::cast exception, but belongs to <typeinfo>
void identify(Base &p)
{
	try
	{
		(void)dynamic_cast<A &>(p);
		std::cout << "A identified" << std::endl;
		return;
	}
	catch (const std::exception &e)
	{
		// std::cerr << e.what() << '\n';
	}
	try
	{
		(void)dynamic_cast<B &>(p);
		std::cout << "B identified" << std::endl;
		return;
	}
	catch (const std::exception &e)
	{
		// std::cerr << e.what() << '\n';
	}
	try
	{
		(void)dynamic_cast<C &>(p);
		std::cout << "C identified" << std::endl;
		return;
	}
	catch (const std::exception &e)
	{
		// std::cerr << e.what() << '\n';
	}
}

int main(void)
{
	Base *obj = generate();

	identify(obj);	//* ver
	identify(*obj); //& ver

	delete obj;
	return 0;
}
