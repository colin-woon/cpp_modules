#include "Ice.hpp"

Ice::Ice() {}

Ice::Ice(const Ice& other) {
    this->value = other.value;
}

Ice& Ice::operator=(const Ice& other) {
    if (this != &other)
    {
	this->value = other.value;
    }
    return *this;
}

Ice::~Ice() {}
