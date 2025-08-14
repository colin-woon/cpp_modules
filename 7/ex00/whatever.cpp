#include "whatever.hpp"

whatever::whatever() {}

whatever::whatever(const whatever &other)
{
	(void)other;
}

whatever &whatever::operator=(const whatever &other)
{
	(void)other;
	return *this;
}

whatever::~whatever() {}
