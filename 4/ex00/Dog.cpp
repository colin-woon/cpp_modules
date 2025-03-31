#include "Dog.hpp"

Dog::Dog() {}

Dog::Dog(const Dog& other) {
    this->value = other.value;
}

Dog& Dog::operator=(const Dog& other) {
    if (this != &other)
    {
	this->value = other.value;
    }
    return *this;
}

Dog::~Dog() {}
