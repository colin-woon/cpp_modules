#include "easyfind.hpp"

void print_line()
{
	std::cout << "----------------------------------------" << std::endl;
}

int main()
{
	// Test with std::vector
	std::cout << "--- Testing with std::vector ---" << std::endl;
	std::vector<int> vec;
	for (int i = 0; i < 10; ++i)
	{
		vec.push_back(i * 2); // 0, 2, 4, 6, 8, 10, 12, 14, 16, 18
	}

	// Test case 1: Value found
	try
	{
		std::cout << "Searching for value 8 in vector..." << std::endl;
		std::vector<int>::iterator it = easyfind(vec, 8);
		std::cout << "Found value: " << *it << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}

	// Test case 2: Value not found
	try
	{
		std::cout << "Searching for value 5 in vector..." << std::endl;
		easyfind(vec, 5);
	}
	catch (const std::exception &e)
	{
		std::cerr << "Caught expected exception: " << e.what() << std::endl;
	}
	print_line();

	// Test with std::list
	std::cout << "--- Testing with std::list ---" << std::endl;
	std::list<int> lst;
	lst.push_back(10);
	lst.push_back(20);
	lst.push_back(30);
	lst.push_back(40);
	lst.push_back(50);

	// Test case 3: Value found
	try
	{
		std::cout << "Searching for value 30 in list..." << std::endl;
		std::list<int>::iterator it = easyfind(lst, 30);
		std::cout << "Found value: " << *it << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}

	// Test case 4: Value not found
	try
	{
		std::cout << "Searching for value 99 in list..." << std::endl;
		easyfind(lst, 99);
	}
	catch (const std::exception &e)
	{
		std::cerr << "Caught expected exception: " << e.what() << std::endl;
	}
	print_line();

	// --- Edge Case Testing ---
	std::cout << "--- Edge Case Testing ---" << std::endl;

	// Test case 5: Empty container
	std::vector<int> empty_vec;
	try
	{
		std::cout << "Searching in empty vector..." << std::endl;
		easyfind(empty_vec, 42);
	}
	catch (const std::exception &e)
	{
		std::cerr << "Caught expected exception: " << e.what() << std::endl;
	}
	print_line();

	// Test case 6: Duplicates (find first occurrence)
	std::vector<int> dup_vec;
	dup_vec.push_back(1);
	dup_vec.push_back(2);
	dup_vec.push_back(2);
	dup_vec.push_back(3);
	try
	{
		std::cout << "Searching for 2 in {1, 2, 2, 3}..." << std::endl;
		std::vector<int>::iterator it = easyfind(dup_vec, 2);
		std::cout << "Found value: " << *it << std::endl;
		// Check if it's the first one
		if (std::distance(dup_vec.begin(), it) == 1)
		{
			std::cout << "Iterator points to the first occurrence." << std::endl;
		}
		else
		{
			std::cout << "Iterator does NOT point to the first occurrence." << std::endl;
		}
	}
	catch (const std::exception &e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}
	print_line();

	// Test case 7: Const container
	const std::vector<int> const_vec = vec;
	try
	{
		std::cout << "Searching for 18 in a const vector..." << std::endl;
		std::vector<int>::const_iterator it = easyfind(const_vec, 18);
		std::cout << "Found value: " << *it << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}
	print_line();

	return 0;
}
