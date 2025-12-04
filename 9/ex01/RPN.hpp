#ifndef RPN_HPP
#define RPN_HPP

#include <stack>
#include <set>
#include <iostream>
#include <exception>
#include <cctype>
#include <cstdlib>

using std::cerr;
using std::cout;
using std::endl;
using std::exception;
using std::set;
using std::stack;

class RPN
{
private:
	stack<int> _stack;
	static const set<char> _allowedOperators;

public:
	RPN();
	RPN(const RPN &other);
	RPN &operator=(const RPN &other);
	~RPN();

	class IncorrectFormatException : public exception
	{
	public:
		const char *what() const throw();
	};

	class ZeroDivisionException : public exception
	{
	public:
		const char *what() const throw();
	};

	void calculate(char op);
	void pushToStack(char input);
	int getResult() const;
	bool isAllowedOperator(char input) const;
};

#endif
