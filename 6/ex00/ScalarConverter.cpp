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

struct myTypes
{
	char tempC;
	int tempI;
	float tempF;
	double tempD;
	bool isNan;
	bool isInfinity;
	bool isNegative;
	bool isNonDisplayable;
	bool hasDecimal;
	bool isDone;
};

void printOutput(myTypes result)
{
	result.isDone = true;
	if (result.isNan)
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		if (result.isInfinity)
		{
			if (result.isNegative)
			{
				std::cout << "float: -inff" << std::endl;
				std::cout << "double: -inf" << std::endl;
			}
			else
			{
				std::cout << "float: +inff" << std::endl;
				std::cout << "double: +inf" << std::endl;
			}
		}
		else
		{
			std::cout << "float: nanf" << std::endl;
			std::cout << "double: nan" << std::endl;
		}
	}
	else
	{
		if (result.isNonDisplayable)
			std::cout << "char: Non displayable" << std::endl;
		else
			std::cout << "char: '" << result.tempC << "'" << std::endl;
		std::cout << "int: " << result.tempI << std::endl;
		if (!result.hasDecimal)
		{
			std::cout << "float: " << std::fixed << std::setprecision(1) << result.tempF << "f" << std::endl;
			std::cout << "double: " << std::fixed << std::setprecision(1) << result.tempD << std::endl;
		}
	}
}

void tryChar(const std::string &input, myTypes &result)
{
	int startIdx = -1;
	if (input.length() == 1 && !std::isdigit(input[0]))
		startIdx = 0;
	else if (input.length() == 3 && input[2] == '\'' && input[0] == '\'')
		startIdx = 1;
	if (startIdx != -1)
	{
		if (!isprint(input[startIdx]))
		{
			result.isNonDisplayable = true;
			result.tempI = 0;
			result.tempF = 0.0f;
			result.tempD = 0.0;
		}
		else
		{
			result.tempC = input[startIdx];
			result.tempI = static_cast<int>(result.tempC);
			result.tempD = static_cast<double>(result.tempC);
			result.tempF = static_cast<float>(result.tempC);
		}
		printOutput(result);
		return;
	}
}

void tryInt(const std::string &input, myTypes &result)
{
	if (input.find('.') != std::string::npos)
	{
		result.hasDecimal = true;
		return;
	}
	else
	{
		char *end_ptr;

		long longNum = strtol(input.c_str(), &end_ptr, 10);
		errno = 0;
		if (*end_ptr != '\0' || longNum > INT_MAX || longNum < INT_MIN || errno == ERANGE)
			result.isNan = true;
		else
		{
			result.tempC = static_cast<char>(longNum);
			result.isNonDisplayable = (longNum < 0 || longNum > 127 || !isprint(result.tempC));
			result.tempI = static_cast<int>(longNum);
			result.tempF = static_cast<float>(longNum);
			result.tempD = static_cast<double>(longNum);
		}
		printOutput(result);
		return;
	}
}

void ScalarConverter::convert(const std::string &input)
{
	myTypes result = {};

	// tryChar(input, result);
	tryInt(input, result);
	if (result.hasDecimal)
	{
	}
}
