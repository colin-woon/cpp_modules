using namespace std;
#include <iostream>

// to use a template, must declare this line first
template <typename T>
// 1. FUNCTION TEMPLATE
T const &max(T const &x, T const &y)
{
	return ((x < y) ? y : x);
}

// 2. CLASS TEMPLATE (DATA STRUCTURE)
// This is useful for different types of linked list, then need to implement different ADT like CRUD
// But STL already handles that kind of scenario
template <typename U>
class List
{
private:
	U *_content;
	List<U> *_next;

public:
	List<U>(T const &content)
	{
	}

	List<U>(List<U> const &list)
	{
	}

	~List<U>(void)
	{
	}

};

int foo(int x)
{
	std::cout << "Long time" << std::endl;
	return x;
}

int main(void)
{
	int a = 21;
	int b = 42;

	// Scope resolution ::
	// <type> explicit instanciation
	cout << ::max<int>(a, b) << endl;
	// Implicit instanciation
	cout << ::max(a, b) << endl;

	cout << ::max(foo(a), foo(b)) << endl;
}
