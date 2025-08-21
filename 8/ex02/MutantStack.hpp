#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <stack>
#include <iostream>
// #include <algorithm>

template <typename T>
class MutantStack : public std::stack<T>
{
public:
	typedef typename std::stack<T>::container_type::iterator iterator;

	MutantStack<T>() : std::stack<T>(){};
	MutantStack<T>(const MutantStack &other) : std::stack<T>(other){};
	MutantStack<T> &operator=(const MutantStack<T> &other)
	{
		if (this != other)
			std::stack<T>::operator=(other);
		return *this;
	};
	~MutantStack<T>(){};

	iterator begin() { return this->c.begin(); };
	iterator end() { return this->c.end(); };
};

#endif
