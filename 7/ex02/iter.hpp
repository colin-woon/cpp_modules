#ifndef ITER_HPP
#define ITER_HPP

#include <cstddef>
#include <iostream>
#include <string>
#include "Array.hpp"

template <typename T>
void iter(Array<T> &array, size_t len, void (*func)(T &))
{
	for (size_t i = 0; i < len; i++)
		func(array[i]);
}

// ------FOR TESTING PURPOSES---------
// A template function to print any type of element
template <typename T>
void printElement(T &element)
{
	std::cout << element << " ";
}

// A function to increment numeric types
template <typename T>
void increment(T &n)
{
	n++;
}

// A function to change a character to uppercase
void toUpper(char &c)
{
	c = std::toupper(c);
}
#endif
