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
	return "Error: could not open file.";
}

const char *BitcoinExchange::InvalidFileExtensionException::what() const throw()
{
	return "Error: expected \"data.csv\" and \"input.txt\"";
}

const char *BitcoinExchange::InvalidDataFormatException::what() const throw()
{
	return "Error: missing value for date.";
}

BitcoinExchange::InvalidInputFormatException::InvalidInputFormatException(const string &line) throw() : badLine(line) {}

const char *BitcoinExchange::InvalidInputFormatException::what() const throw()
{
	return "Error: bad input";
}

BitcoinExchange::InvalidInputFormatException::~InvalidInputFormatException() throw() {}

const char *BitcoinExchange::InvalidDateFormatException::what() const throw()
{
	return "Error: invalid date format, expected YYYY-MM-DD";
}

const char *BitcoinExchange::TooLargeValueException::what() const throw()
{
	return "Error: too large a number.";
}

const char *BitcoinExchange::NegativeValueException::what() const throw()
{
	return "Error: not a positive number.";
}

const char *BitcoinExchange::InvalidValueTypeException::what() const throw()
{
	return "Error: not a number.";
}

const char *BitcoinExchange::DateNotFoundException::what() const throw()
{
	return "Error: date not found.";
}

bool BitcoinExchange::isInvalidDate(const string &date)
{
	// The required format length is YYYY-MM-DD (10 characters)
	if (date.length() != 10 || date[4] != '-' || date[7] != '-')
		return true;

	// 1. Manually Extract Components
	string year_str = date.substr(0, 4);
	string month_str = date.substr(5, 2);
	string day_str = date.substr(8, 2);

	int year = 0;
	int month = 0;
	int day = 0;

	// 2. Convert to integers using stringstream, >> is operator overloaded to convert lhs to rhs type
	// >> operator will return stream itself, false if failed, ! inverts that, so it'll be true that isInvalidDate
	stringstream ss_y(year_str);
	if (!(ss_y >> year))
		return true;

	stringstream ss_m(month_str);
	if (!(ss_m >> month))
		return true;

	stringstream ss_d(day_str);
	if (!(ss_d >> day))
		return true;

	// Simple range checks (e.g., month 0 is invalid before tm conversion)
	if (month < 1 || month > 12 || day < 1 || day > 31)
		return true;

	// 3. Setup the struct tm (The Traditional Way)
	// Initialize to all zeros
	// Years since 1900 (a design choice back in the 70s-80s as memory was expensive, only few kb-mbs of RAM, so they store the offset, eg year 1999 = 99 years from 1900, avoids the y2k problem)
	// Months since January (0-11)
	// Day of the month (1-31)
	std::tm time_struct;
	std::memset(&time_struct, 0, sizeof(time_struct));
	time_struct.tm_year = year - 1900;
	time_struct.tm_mon = month - 1;
	time_struct.tm_mday = day;

	// Save the original values for comparison
	int original_year = time_struct.tm_year;
	int original_month = time_struct.tm_mon;
	int original_day = time_struct.tm_mday;

	// 4. Use mktime for Validation (Normalization)
	// mktime attempts to convert the struct into a time_t value.
	// If the provided time cannot be represented as a time_t value(usually because it 's an impossibly early or late date/time for the system' s time_t range), mktime returns the special value(time_t) - 1
	if (std::mktime(&time_struct) == (std::time_t)-1)
		return true;

	// 5. Compare: If mktime changed the date, it was invalid.
	// For example, months are 0-11. If you pass it a tm_mon of 12 (which means the 13th month, or January of the next year), mktime will correct tm_mon to 0 and increment tm_year.
	if (time_struct.tm_year != original_year ||
		time_struct.tm_mon != original_month ||
		time_struct.tm_mday != original_day)
	{
		return true;
	}

	return false;
}

bool BitcoinExchange::isValidValue(const string &value)
{
	stringstream ss(value);
	float number;

	ss >> number;

	// fail() checks if extraction failed (e.g., "hello")
	// !ss.eof() checks if we reached the end of the string (i.e., trailing chars like "10.5abc")
	// isdigit(ss.peek()) is a simpler (but slightly less robust) alternative to checking !ss.eof()
	if (ss.fail() || !ss.eof())
		throw InvalidValueTypeException();
	if (number < 0)
		throw NegativeValueException();
	else if (number > 1000)
		throw TooLargeValueException();
	return true;
}

// doesnt get concerned about file extension, just treats everything as raw bytes
void BitcoinExchange::extractFile(const string &fileName, const char &delimeter, map<string, string> &map)
{
	ifstream file(fileName.c_str());
	string line, date, value;

	if (!file.is_open())
		throw FileOpenException();

	while (getline(file, line))
	{
		stringstream ss(line);

		if (line.empty())
			continue;

		if (getline(ss, date, delimeter))
		{
			if (date == "date")
				continue;
			if (getline(ss, value))
				map[date] = value;
			else
				throw InvalidDataFormatException();
		}
	}
	file.close();
}

BitcoinExchange::BitcoinExchange(const string &csvFile, char csvFileDelimeter)
{
	if (csvFile != "data.csv")
		throw InvalidFileExtensionException();
	extractFile(csvFile, csvFileDelimeter, _priceAction);
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

// lower_bound returns the value immediately after the inputDate if not found, if completely not in the range, will return last iterator
string BitcoinExchange::getPrice(string &inputDate) const
{
	constMapIterator priceActionIt = _priceAction.find(inputDate);
	if (priceActionIt == _priceAction.end())
	{
		priceActionIt = _priceAction.lower_bound(inputDate);
		// if inputDate is earlier than earliest date in map, must throw exception so later decrement wont segfault
		if (priceActionIt == _priceAction.begin())
		{
			if (priceActionIt->first != inputDate)
				throw DateNotFoundException();
		}

		// Get the previous iterator (the closest date <= inputDate)
		if (priceActionIt != _priceAction.begin())
			priceActionIt--;
	}
	return priceActionIt->second;
}

void BitcoinExchange::calculateResult(string &inputValue, string &priceRate, string &inputDate) const
{
	stringstream ss;
	float inputValueFloat;
	float priceRateFloat;
	float resultFloat;
	std::string result;

	ss.str(inputValue);
	ss >> inputValueFloat;
	ss.clear();

	ss.str(priceRate);
	ss >> priceRateFloat;
	ss.clear();

	resultFloat = inputValueFloat * priceRateFloat;

	ss.str("");
	ss << resultFloat;
	result = ss.str();

	cout << inputDate << " => " << inputValue << " = " << result << endl;
}

void BitcoinExchange::calculateExchangeRate(const string &inputFile, const string &delimeter) const
{
	string line;

	if (inputFile != "input.txt")
		throw InvalidFileExtensionException();

	ifstream inputFileStream(inputFile.c_str());
	if (!inputFileStream.is_open())
		throw FileOpenException();

	getline(inputFileStream, line); // to skip the header line (date | value)

	while (getline(inputFileStream, line))
	{
		std::string inputDate;
		std::string inputValue;
		std::string priceRate;

		try
		{
			size_t delimeterPos = line.find(delimeter);
			if (delimeterPos == string::npos)
				throw InvalidInputFormatException(line);

			inputDate = line.substr(0, delimeterPos);
			if (isInvalidDate(inputDate))
				throw InvalidDateFormatException();

			priceRate = getPrice(inputDate);

			inputValue = line.substr(delimeterPos + delimeter.size());
			if (inputValue.empty())
				throw InvalidInputFormatException(line);

			if (isValidValue(inputValue))
				calculateResult(inputValue, priceRate, inputDate);
		}
		catch (const InvalidInputFormatException &e)
		{
			cout << e.what() << " => " << e.badLine << endl;
		}
		catch (const exception &e)
		{
			cout << e.what() << endl;
		}
	}
}
