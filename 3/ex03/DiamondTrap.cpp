#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() {}

DiamondTrap::DiamondTrap(const DiamondTrap& other) {
    this->value = other.value;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& other) {
    if (this != &other)
    {
	this->value = other.value;
    }
    return *this;
}

DiamondTrap::~DiamondTrap() {}
