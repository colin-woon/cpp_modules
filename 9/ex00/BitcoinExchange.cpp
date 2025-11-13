#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other)
{
	this->_priceAction = other._priceAction;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other)
{
	if (this != &other)
	{
		this->_priceAction = other._priceAction;
	}
	return *this;
}

BitcoinExchange::~BitcoinExchange() {}

const char *BitcoinExchange::FileOpenException::what() const throw()
{
	return "Error: Could not open file.";
}

const char *BitcoinExchange::InvalidFileFormatException::what() const throw()
{
	return "Error: Missing value for date.";
}

BitcoinExchange::BitcoinExchange(const string &fileName)
{
	ifstream file(fileName.c_str());
	string line, key, value;

	if (!file.is_open())
		throw FileOpenException();

	while (getline(file, line))
	{
		stringstream ss(line);

		if (line.empty())
			continue;

		if (getline(ss, key, ','))
		{
			if (key == "date")
				continue;
			if (getline(ss, value))
				_priceAction[key] = value;
			else
				throw InvalidFileFormatException();
		}
	}
	file.close();
}

void BitcoinExchange::getAllDetails() const
{
	cout << "Date" << " | " << "Price" << endl;
	for (constMapIterator it = _priceAction.begin(); it != _priceAction.end(); it++)
	{
		const string &key = it->first;
		const string &value = it->second;
		cout << key << " | " << value << endl;
	}
}
