#ifndef WHATEVER_HPP
#define WHATEVER_HPP

#include "whatever.tpp"
#include <iostream>

class whatever
{
public:
	whatever();
	whatever(const whatever &other);
	whatever &operator=(const whatever &other);
	~whatever();
};

#endif
