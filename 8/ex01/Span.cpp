#include "Span.hpp"

Span::Span() {}

Span::Span(const Span& other) {
    this->value = other.value;
}

Span& Span::operator=(const Span& other) {
    if (this != &other)
    {
	this->value = other.value;
    }
    return *this;
}

Span::~Span() {}
