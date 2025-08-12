#ifndef DATA_HPP
#define DATA_HPP

#include <string>

class Data
{
private:
	std::string _message;

public:
	Data();
	Data(const Data &other);
	Data &operator=(const Data &other);
	~Data();

	Data(std::string newMessage);
	std::string getMessage() const;
};

#endif
