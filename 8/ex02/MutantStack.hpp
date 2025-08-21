#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <stack>
#include <iostream>

// typename
// Required when accessing types defined inside template parameters.
// Used in templates to tell the compiler that a dependent name is a type.

// typedef
// gives an alias

// 1. std::stack<T>::container_type is a type defined inside std::stack<T>.
// 2. iterator is a type defined inside container_type.
// 3. typename tells the compiler that std::stack<T>::container_type::iterator is a type, not a static member or function.
// 4. typedef ... iterator; creates an alias called iterator for this type.
// WHY: so the iterator will be based on its respective type (vector, deque, list)

// container_type is a type alias defined inside std::stack

// https://cplusplus.com/reference/stack/stack/
// template <class T, class Container = deque<T>> class stack;
// default container is deque, if you do std::stack<int, std::list<int> >, container becomes vector

// iterator : read / write access
// const_iterator : read - only access

template <typename T>
class MutantStack : public std::stack<T>
{
public:
	typedef typename std::stack<T>::container_type::iterator iterator;
	typedef typename std::stack<T>::container_type::const_iterator const_iterator;

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

	const_iterator begin() const { return this->c.begin(); };
	const_iterator end() const { return this->c.end(); };
};

#endif
