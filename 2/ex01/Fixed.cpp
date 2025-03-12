#include "Fixed.hpp"

Fixed::Fixed() : value(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &other)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

Fixed &Fixed::operator=(const Fixed &other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
	{
		this->value = other.getRawBits();
	}
	return *this;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(int const value)
{
	std::cout << "Int constructor called" << std::endl;
	if (value > (INT_MAX >> Fixed::bits) || value < (INT_MIN >> Fixed::bits))
		throw std::invalid_argument("Error: Integer overflow in conversion");
	else
		setRawBits(value << Fixed::bits);
}

Fixed::Fixed(float const value)
{
	std::cout << "Float constructor called" << std::endl;
	double float_value = (double)value * (1 << Fixed::bits);

	if (float_value > (double)INT_MAX || float_value < (double)INT_MIN)
		throw std::invalid_argument("Error: Float to Integer overflow in conversion");
	else
		setRawBits(roundf(float_value));
}

float Fixed::toFloat(void) const
{
	return (float)this->value / (1 << Fixed::bits);
}

int Fixed::toInt(void) const
{
	return this->value >> Fixed::bits;
}

int Fixed::getRawBits(void) const
{
	return this->value;
}

void Fixed::setRawBits(int const raw)
{
	this->value = raw;
}

std::ostream &operator<<(std::ostream &out, Fixed const &value)
{
	out << value.toFloat();
	return out;
}
