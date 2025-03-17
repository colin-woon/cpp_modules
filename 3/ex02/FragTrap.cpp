#include "FragTrap.hpp"

FragTrap::FragTrap() {}

FragTrap::FragTrap(const FragTrap& other) {
    this->value = other.value;
}

FragTrap& FragTrap::operator=(const FragTrap& other) {
    if (this != &other)
    {
	this->value = other.value;
    }
    return *this;
}

FragTrap::~FragTrap() {}
