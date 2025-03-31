#include "Cat.hpp"

Cat::Cat() {}

Cat::Cat(const Cat& other) {
    this->value = other.value;
}

Cat& Cat::operator=(const Cat& other) {
    if (this != &other)
    {
	this->value = other.value;
    }
    return *this;
}

Cat::~Cat() {}
