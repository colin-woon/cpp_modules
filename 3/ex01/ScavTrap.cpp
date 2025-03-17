#include "ScavTrap.hpp"

ScavTrap::ScavTrap() {}

ScavTrap::ScavTrap(const ScavTrap& other) {
    this->value = other.value;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other) {
    if (this != &other)
    {
	this->value = other.value;
    }
    return *this;
}

ScavTrap::~ScavTrap() {}
