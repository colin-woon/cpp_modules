#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <map>
#include <string>
#include <iostream>
#include <sstream>
#include <fstream>

using std::cerr;
using std::cout;
using std::endl;
using std::ifstream;
using std::map;
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

	class InvalidFileFormatException : public std::exception
	{
	public:
		const char *what() const throw();
	};

	// map<string, string> &extractFile(const string &fileName, const char &delimeter);
	void extractFile(const string &fileName, const char &delimeter, map<string, string> &map);
	BitcoinExchange(const string &csvFile, char csvFileDelimeter, const string &inputFile, char inputFileDelimeter);
	void getAllDetails() const;
};

#endif
