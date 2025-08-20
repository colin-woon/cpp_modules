#include "Span.hpp"

Span::Span() : _maxSize(0), _numbers() {}

Span::Span(const Span &other) : _maxSize(other._maxSize), _numbers(other._numbers) {}

Span &Span::operator=(const Span &other)
{
	if (this != &other)
	{
		this->_maxSize = other._maxSize;
		this->_numbers = other._numbers;
	}
	return *this;
}

Span::~Span() {}

const char *Span::FullNumbersException::what() const throw()
{
	return "Max capacity reached!";
}

const char *Span::NoSpanFoundException::what() const throw()
{
	return "No span found!";
}

Span::Span(unsigned int init) : _maxSize(init), _numbers()
{
	_numbers.reserve(init);
}

void Span::addNumber(int num)
{
	if (_numbers.size() >= _maxSize)
		throw FullNumbersException();
	_numbers.push_back(num);
}

int Span::shortestSpan() const
{
	if (_numbers.size() < 2)
		throw NoSpanFoundException();

	std::vector<int> sorted = _numbers;
	std::sort(sorted.begin(), sorted.end());

	int minSpan = sorted[1] - sorted[0];
	for (std::vector<int>::iterator it = sorted.begin() + 1; it != sorted.end(); it++)
	{
		int span = *it - *(it - 1);
		if (span < minSpan)
			minSpan = span;
	}
	return minSpan;
}

int Span::longestSpan() const
{
	if (_numbers.size() < 2)
		throw NoSpanFoundException();

	int min = *std::min_element(_numbers.begin(), _numbers.end());
	int max = *std::max_element(_numbers.begin(), _numbers.end());
	return (max - min);
}

void Span::fillNumbers(std::vector<int>::iterator from, std::vector<int>::iterator to)
{
	for (std::vector<int>::iterator it = from; it != to; it++)
	{
		if (_numbers.size() >= _maxSize)
			throw FullNumbersException();
		_numbers.push_back(*it);
	}
}

std::vector<int> Span::getNumbers() const
{
	return _numbers;
}

unsigned int Span::getMaxSize() const
{
	return _maxSize;
}
