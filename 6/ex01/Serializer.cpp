#include "Serializer.hpp"

Serializer::Serializer() {}

Serializer::Serializer(const Serializer& other) {
    this->value = other.value;
}

Serializer& Serializer::operator=(const Serializer& other) {
    if (this != &other)
    {
	this->value = other.value;
    }
    return *this;
}

Serializer::~Serializer() {}
