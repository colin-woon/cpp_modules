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
	bool isFloat;
	bool isDone;
	int precisionValue;
};

void printOutput(myTypes &result)
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
		std::cout << "float: " << std::fixed << std::setprecision(result.precisionValue) << result.tempF << "f" << std::endl;
		std::cout << "double: " << std::fixed << std::setprecision(result.precisionValue) << result.tempD << std::endl;
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
	if (input.length() == 1 && std::isdigit(input[0]))
	{
		result.tempC = static_cast<char>(result.tempI);
		result.isNonDisplayable = (!isprint(result.tempC));
		result.tempI = static_cast<int>(input[0]);
		result.tempF = static_cast<float>(result.tempI);
		result.tempD = static_cast<double>(result.tempI);
		printOutput(result);
		return;
	}
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

void setPrecision(const std::string &input, myTypes &result)
{
	int decimalPos = input.find('.');
	int end = input.size();
	if (input[input.length() - 1] == 'f')
		end = end - 1;
	result.precisionValue = end - decimalPos - 1;
	if (result.precisionValue < 1)
		result.precisionValue = 1;
}

void tryDouble(const std::string &input, myTypes &result)
{
	if (result.hasDecimal)
	{
		char *end_ptr;
		errno = 0;
		result.tempD = strtod(input.c_str(), &end_ptr);
		if (*end_ptr != '\0' || errno == ERANGE)
		{
			if (*end_ptr == 'f' && *(end_ptr + 1) == '\0')
			{
				result.isFloat = true;
				return;
			}
			result.isNan = true;
		}
		else
		{
			result.tempC = static_cast<char>(result.tempD);
			result.isNonDisplayable = (result.tempD < 0 || result.tempD > 127 || !isprint(result.tempC));
			result.tempI = static_cast<int>(result.tempD);
			result.tempF = static_cast<float>(result.tempD);
			setPrecision(input, result);
		}
		printOutput(result);
	}
}

void tryFloat(const std::string &input, myTypes &result)
{
	if (result.isFloat)
	{
		char *end_ptr;
		errno = 0;
		if (errno == ERANGE)
			result.isNan = true;
		else
		{
			result.tempF = strtof(input.c_str(), &end_ptr);
			result.tempC = static_cast<char>(result.tempF);
			result.isNonDisplayable = (result.tempF < 0 || result.tempF > 127 || !isprint(result.tempC));
			result.tempI = static_cast<int>(result.tempF);
			result.tempD = static_cast<double>(result.tempF);
			setPrecision(input, result);
		}
		printOutput(result);
	}
}

void ScalarConverter::convert(const std::string &input)
{
	myTypes result = {};
	result.precisionValue = 1;

	for (int tries = 0; tries < 4 && !result.isDone; tries++)
	{
		switch (tries)
		{
		case 0:
			tryChar(input, result);
			break;
		case 1:
			tryInt(input, result);
			break;
		case 2:
			tryDouble(input, result);
			break;
		case 3:
			tryFloat(input, result);
			break;
		}
	}
	if (!result.isDone)
	{
		result.isNan = true;
		printOutput(result);
	}
}
