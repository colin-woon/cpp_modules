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

const char *BitcoinExchange::InvalidFileExtensionException::what() const throw()
{
	return "Error: Expected \"data.csv\" and \"input.txt\"";
}

const char *BitcoinExchange::InvalidFileFormatException::what() const throw()
{
	return "Error: Missing value for date.";
}

void BitcoinExchange::extractFile(const string &fileName, const char &delimeter, map<string, string> &map)
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

		if (getline(ss, key, delimeter))
		{
			if (key == "date")
				continue;
			if (getline(ss, value))
				map[key] = value;
			else
				throw InvalidFileFormatException();
		}
	}
	file.close();
}

BitcoinExchange::BitcoinExchange(const string &csvFile, char csvFileDelimeter, const string &inputFile, char inputFileDelimeter)
{
	if (csvFile != "data.csv" && inputFile != "input.txt")
		throw InvalidFileExtensionException();
	extractFile(csvFile, csvFileDelimeter, _priceAction);
	extractFile(inputFile, inputFileDelimeter, _exchangeRate);
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

	cout << endl;
	cout << "Date" << " | " << "Count" << endl;
	for (constMapIterator it = _exchangeRate.begin(); it != _exchangeRate.end(); it++)
	{
		const string &key = it->first;
		const string &value = it->second;
		cout << key << " | " << value << endl;
	}
}
