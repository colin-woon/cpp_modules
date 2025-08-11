#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <stdio.h>

#include <iostream>
#include <iomanip>
#include <cctype>
#include <cstdlib>
#include <cstring>
#include <climits>

class ScalarConverter
{
public:
	static void convert(const std::string &input);

private:
	ScalarConverter();
	ScalarConverter(const ScalarConverter &other);
	ScalarConverter &operator=(const ScalarConverter &other);
	~ScalarConverter();
};

#endif
