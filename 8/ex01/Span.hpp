#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <vector>
#include <algorithm>

class Span
{
private:
	unsigned int _maxSize;
	std::vector<int> _numbers;

public:
	Span();
	Span(const Span &other);
	Span &operator=(const Span &other);
	~Span();

	class FullNumbersException : public std::exception
	{
	public:
		const char *what() const throw();
	};
	class NoSpanFoundException : public std::exception
	{
	public:
		const char *what() const throw();
	};

	Span(unsigned int init);
	void addNumber(int num);
	int shortestSpan() const;
	int longestSpan() const;
	void fillNumbers(std::vector<int>::iterator from, std::vector<int>::iterator to);

	std::vector<int> getNumbers() const;
	unsigned int getMaxSize() const;
};

#endif
