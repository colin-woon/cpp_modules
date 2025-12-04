#include "RPN.hpp"

set<char> createAllowedOperatorsSet()
{
	set<char> temp_set;

	temp_set.insert('+');
	temp_set.insert('-');
	temp_set.insert('*');
	temp_set.insert('/');

	return temp_set;
}

const set<char> RPN::_allowedOperators = createAllowedOperatorsSet();

RPN::RPN() : _stack() {}

RPN::RPN(const RPN &other)
{
	this->_stack = other._stack;
}

RPN &RPN::operator=(const RPN &other)
{
	if (this != &other)
	{
		this->_stack = other._stack;
	}
	return *this;
}

RPN::~RPN() {}

const char *RPN::IncorrectFormatException::what() const throw()
{
	return "Error";
}

const char *RPN::ZeroDivisionException::what() const throw()
{
	return "Error: cannot divide by zero";
}

void RPN::calculate(char op)
{
	if (_stack.size() < 2)
		throw IncorrectFormatException();
	int valuePopped = _stack.top();
	_stack.pop();
	if (op == '+')
		_stack.top() += valuePopped;
	else if (op == '-')
		_stack.top() -= valuePopped;
	else if (op == '/')
	{
		if (valuePopped == 0)
			throw ZeroDivisionException();
		_stack.top() /= valuePopped;
	}
	else if (op == '*')
		_stack.top() *= valuePopped;
}

void RPN::pushToStack(char input)
{
	int digit = input - '0';
	_stack.push(digit);
}

int RPN::getResult() const
{
	return _stack.top();
}

bool RPN::isAllowedOperator(char input) const
{
	if (_allowedOperators.find(input) != _allowedOperators.end())
		return true;
	return false;
}
