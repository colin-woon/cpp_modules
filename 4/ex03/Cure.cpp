#include "Cure.hpp"

Cure::Cure() {}

Cure::Cure(const Cure& other) {
    this->value = other.value;
}

Cure& Cure::operator=(const Cure& other) {
    if (this != &other)
    {
	this->value = other.value;
    }
    return *this;
}

Cure::~Cure() {}
