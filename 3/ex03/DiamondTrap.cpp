#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap("_clap_name"), ScavTrap(), FragTrap(), _name("") { std::cout << "Unnamed is type DiamondTrap" << std::endl; }

DiamondTrap::DiamondTrap(const DiamondTrap &other) : ClapTrap(other.getName() + "_clap_name"), ScavTrap(other), FragTrap(other), _name(other.getName())
{
	std::cout << "DiamondTrap copy constructor called for " << other.getName() << "!" << std::endl;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &other)
{
	if (this != &other)
	{
		ClapTrap::operator=(other);
		ScavTrap::operator=(other);
		FragTrap::operator=(other);
		_name = other.getName();
		std::cout << "DiamondTrap assignment operator called for " << other.getName() << "!" << std::endl;
	}
	return *this;
}

DiamondTrap::~DiamondTrap() { std::cout << "DiamondTrap is destroyed" << std::endl; }
