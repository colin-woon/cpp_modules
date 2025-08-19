#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>

class Span
{
private:
	unsigned int _numbers[];

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
	void addNumber(unsigned int num);
	unsigned int shortestSpan() const;
	unsigned int longestSpan() const;
	void fillNumbers();

	unsigned int getNumbers() const;
};

#endif
