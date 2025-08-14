#include <iostream>

// 1. Generic Template
template <typename T, typename U>
class MyClass
{
public:
	MyClass()
	{
		std::cout << "Using generic template <T, U>" << std::endl;
	}
};

// 2. Partial Specialization
// where U is an int
template <typename T>
class MyClass<T, int>
{
public:
	MyClass()
	{
		std::cout << "Using partial specialization <T, int>" << std::endl;
	}
};

// 3. Full Specialization
// where T is int and U is char
template <>
class MyClass<int, char>
{
public:
	MyClass()
	{
		std::cout << "Using full specialization <int, char>" << std::endl;
	}
};
