#include "AMateria.hpp"

AMateria::AMateria() : _type("none")
{
	// std::cout << "AMateria Default constructor called" << std::endl;
}

AMateria::AMateria(const AMateria &other) : _type(other.getType()) {}

AMateria &AMateria::operator=(const AMateria &other)
{
	if (this != &other)
		this->setType(other.getType());
	return *this;
}

AMateria::~AMateria()
{
	// std::cout << "AMateria Destructor called" << std::endl;
}

void AMateria::setType(std::string const &type)
{
	this->_type = type;
}

AMateria::AMateria(std::string const &type) : _type(type)
{
	//  std::cout << "AMateria Constructor called" << std::endl;
}

std::string const &AMateria::getType() const
{
	return this->_type;
}

void AMateria::use(ICharacter &target)
{
	std::cout << "AMateria use called on " << target.getName() << std::endl;
}
