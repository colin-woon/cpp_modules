#include "Animal.hpp"

Animal::Animal() {}

Animal::Animal(const Animal& other) {
    this->value = other.value;
}

Animal& Animal::operator=(const Animal& other) {
    if (this != &other)
    {
	this->value = other.value;
    }
    return *this;
}

Animal::~Animal() {}
