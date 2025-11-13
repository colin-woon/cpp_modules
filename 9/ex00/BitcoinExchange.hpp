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

	class InvalidFileFormatException : public std::exception
	{
	public:
		const char *what() const throw();
	};

	BitcoinExchange(const string &fileName);
	void getAllDetails() const;
};

#endif
