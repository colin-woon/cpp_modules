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
	for (int i = 0; i < std::vector<int>::max_size(); ++i)
		values.push_back(i);

	Span spam(std::vector<int>::max_size());
	spam.fillNumbers(values.begin(), values.end());
	return 0;
}
