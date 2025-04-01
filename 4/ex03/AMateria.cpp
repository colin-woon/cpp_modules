#include "AMateria.hpp"

AMateria::AMateria() {}

AMateria::AMateria(const AMateria& other) {
    this->value = other.value;
}

AMateria& AMateria::operator=(const AMateria& other) {
    if (this != &other)
    {
	this->value = other.value;
    }
    return *this;
}

AMateria::~AMateria() {}
