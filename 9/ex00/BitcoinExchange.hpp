#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <map>
#include <string>
#include <iostream>
#include <sstream>
#include <fstream>
#include <ctime>
#include <cstring>
#include <exception>

using std::cerr;
using std::cout;
using std::endl;
using std::exception;
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
	static void extractFile(const string &fileName, const char &delimeter, map<string, string> &map);
	static bool isInvalidDate(const string &date);
	static bool isValidValue(const string &value);
	string getPrice(string &inputDate) const;
	void calculateResult(string &inputValue, string &priceRate, string &inputDate) const;

public:
	BitcoinExchange();
	BitcoinExchange(const BitcoinExchange &other);
	BitcoinExchange &operator=(const BitcoinExchange &other);
	~BitcoinExchange();

	class FileOpenException : public exception
	{
	public:
		const char *what() const throw();
	};

	class InvalidFileExtensionException : public exception
	{
	public:
		const char *what() const throw();
	};

	class InvalidDataFormatException : public exception
	{
	public:
		const char *what() const throw();
	};

	class InvalidInputFormatException : public exception
	{
	public:
		string badLine;
		InvalidInputFormatException(const string &line) throw();
		const char *what() const throw();
		virtual ~InvalidInputFormatException() throw();
	};

	class InvalidDateFormatException : public exception
	{
	public:
		const char *what() const throw();
	};

	class TooLargeValueException : public exception
	{
	public:
		const char *what() const throw();
	};

	class NegativeValueException : public exception
	{
	public:
		const char *what() const throw();
	};

	class InvalidValueTypeException : public exception
	{
	public:
		const char *what() const throw();
	};

	class DateNotFoundException : public exception
	{
	public:
		const char *what() const throw();
	};

	BitcoinExchange(const string &csvFile, char csvFileDelimeter);
	void getAllDetails() const;
	void calculateExchangeRate(const string &inputFile, const string &delimeter) const;
};

#endif
