#include <iostream>
#include <string>
#include "iter.hpp"

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

int main(void)
{
	// Test with an array of integers
	int int_array[] = {0, 1, 2, 3, 4};
	size_t int_len = sizeof(int_array) / sizeof(int);

	std::cout << "Original int array: ";
	iter(int_array, int_len, printElement<int>);
	std::cout << std::endl;

	iter(int_array, int_len, increment<int>);

	std::cout << "Incremented int array: ";
	iter(int_array, int_len, printElement<int>);
	std::cout << std::endl
			  << std::endl;

	// Test with an array of strings
	std::string str_array[] = {"hello", "world", "this", "is", "a", "test"};
	size_t str_len = sizeof(str_array) / sizeof(std::string);

	std::cout << "Original string array: ";
	iter(str_array, str_len, printElement<std::string>);
	std::cout << std::endl
			  << std::endl;

	// Test with an array of characters
	char char_array[] = "abcdef";
	size_t char_len = sizeof(char_array) / sizeof(char) - 1; // Exclude null terminator

	std::cout << "Original char array: ";
	iter(char_array, char_len, printElement<char>);
	std::cout << std::endl;

	iter(char_array, char_len, toUpper);

	std::cout << "Uppercase char array: ";
	iter(char_array, char_len, printElement<char>);
	std::cout << std::endl;

	return 0;
}
