#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter &other)
{
	(void)other;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other)
{
	(void)other;
	return *this;
}

ScalarConverter::~ScalarConverter() {}

// void convert_to_char(const std::string &input)
// {
// 	const char *temp = input.c_str();

// 	std::cout << "char: " for (int i = 0; temp[i] != '\0'; i++)
// 	{
// 		char current_char = temp[i];

// 		if (isprint(static_cast<unsigned char>(current_char)))
// 			std::cout << current_char;
// 		else
// 			std::cout << "NON-DISPLAYABLE";
// 	}
// 	std::cout << std::endl;
// }

void ScalarConverter::convert(const std::string &input)
{
	const char *temp = input.c_str();
	// char temp_char;
	// int temp_int;
	// float temp_float;
	double temp_double;

	char *end_ptr;
	temp_double = strtod(temp, &end_ptr);

	std::cout << std::fixed << std::setprecision(strlen(temp)) << temp_double << std::endl;
	// if ()
}
