#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <map>
#include <string>
#include <iostream>
#include <sstream>
#include <fstream>
#include <ctime>

using std::cerr;
using std::cout;
using std::endl;
using std::ifstream;
using std::map;
using std::mktime;
using std::string;
using std::stringstream;

class BitcoinExchange
{
public:
	typedef map<string, string>::const_iterator constMapIterator;
	typedef map<string, string>::iterator MapIterator;

private:
	map<string, string> _priceAction;
	map<string, string> _exchangeRate;
	static void extractFile(const string &fileName, const char &delimeter, map<string, string> &map, bool isInputFile);
	static bool isInvalidDate(const string &date);
	static bool isValidValue(const string &value);

public:
	BitcoinExchange();
	BitcoinExchange(const BitcoinExchange &other);
	BitcoinExchange &operator=(const BitcoinExchange &other);
	~BitcoinExchange();

	class FileOpenException : public std::exception
	{
	public:
		const char *what() const throw();
	};

	class InvalidFileExtensionException : public std::exception
	{
	public:
		const char *what() const throw();
	};

	class InvalidDataFormatException : public std::exception
	{
	public:
		const char *what() const throw();
	};

	class InvalidDateFormatException : public std::exception
	{
	public:
		const char *what() const throw();
	};

	class TooLargeValueException : public std::exception
	{
	public:
		const char *what() const throw();
	};

	class NegativeValueException : public std::exception
	{
	public:
		const char *what() const throw();
	};

	BitcoinExchange(const string &csvFile, char csvFileDelimeter, const string &inputFile, char inputFileDelimeter);
	void getAllDetails() const;
};

#endif
