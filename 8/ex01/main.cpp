#include "Span.hpp"

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
	size_t testSize = 100000;
	for (int i = 0; i < testSize; ++i)
		values.push_back(i);

	Span spam(testSize);
	spam.fillNumbers(values.begin(), values.end());
	std::cout << spam.shortestSpan() << std::endl;
	std::cout << spam.longestSpan() << std::endl;

	return 0;
}
