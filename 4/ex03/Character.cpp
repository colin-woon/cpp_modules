#include "Character.hpp"

Character::Character() {}

Character::Character(const Character& other) {
    this->value = other.value;
}

Character& Character::operator=(const Character& other) {
    if (this != &other)
    {
	this->value = other.value;
    }
    return *this;
}

Character::~Character() {}
