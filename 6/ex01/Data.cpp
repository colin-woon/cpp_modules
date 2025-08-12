#include "Data.hpp"

Data::Data() : _message("None") {}

Data::Data(const Data &other)
{
	this->_message = other._message;
}

Data &Data::operator=(const Data &other)
{
	if (this != &other)
	{
		this->_message = other._message;
	}
	return *this;
}

Data::~Data() {}

Data::Data(std::string newMessage) : _message(newMessage) {}

std::string Data::getMessage() const
{
	return this->_message;
}
