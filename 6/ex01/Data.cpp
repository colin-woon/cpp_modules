#include "Data.hpp"

Data::Data() {}

Data::Data(const Data& other) {
    this->value = other.value;
}

Data& Data::operator=(const Data& other) {
    if (this != &other)
    {
	this->value = other.value;
    }
    return *this;
}

Data::~Data() {}
