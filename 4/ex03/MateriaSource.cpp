#include "MateriaSource.hpp"

MateriaSource::MateriaSource() {}

MateriaSource::MateriaSource(const MateriaSource& other) {
    this->value = other.value;
}

MateriaSource& MateriaSource::operator=(const MateriaSource& other) {
    if (this != &other)
    {
	this->value = other.value;
    }
    return *this;
}

MateriaSource::~MateriaSource() {}
