#include "Intern.hpp"

Intern::Intern() {}

Intern::Intern(const Intern& other) {
    this->value = other.value;
}

Intern& Intern::operator=(const Intern& other) {
    if (this != &other)
    {
	this->value = other.value;
    }
    return *this;
}

Intern::~Intern() {}
