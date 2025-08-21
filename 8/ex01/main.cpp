#include "Span.hpp"

// You cannot use INT_MAX (which is typically 2,147,483,647) for testSize primarily due to memory constraints.

// Here's a breakdown:

// Memory Allocation: Your code attempts to create a std::vector<int> and populate it with testSize elements.

// An int usually occupies 4 bytes.
// To store INT_MAX integers, you would need 2,147,483,647 * 4 bytes, which is approximately 8.6 gigabytes of memory.
// std::bad_alloc: Most systems cannot allocate such a large, contiguous block of memory for a single data structure. When your std::vector tries to request this much memory from the operating system, the allocation will fail, and the program will throw a std::bad_alloc exception and terminate.

// Performance: Even if you had enough memory, the loop to populate the vector would run over two billion times, which would take an impractically long time to complete.

int main()
{
	Span sp = Span(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;

	std::vector<int> values;
	size_t testSize = 10000000;
	for (int i = 0; i < testSize; ++i)
		values.push_back(i);

	Span spam(testSize);
	try
	{
		spam.fillNumbers(values.begin(), values.end());
		spam.addNumber(1);
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << spam.shortestSpan() << std::endl;
	std::cout << spam.longestSpan() << std::endl;

	return 0;
}
