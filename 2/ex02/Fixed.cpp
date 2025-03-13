#include "Fixed.hpp"

Fixed::Fixed() : value(0) {}

Fixed::Fixed(const Fixed &other)
{
	*this = other;
}

Fixed &Fixed::operator=(const Fixed &other)
{
	if (this != &other)
		this->value = other.getRawBits();
	return *this;
}

Fixed::~Fixed() {}

Fixed::Fixed(int const value)
{
	if (value > (INT_MAX >> Fixed::bits) || value < (INT_MIN >> Fixed::bits))
		throw std::invalid_argument("Error: Integer overflow in conversion");
	else
		this->value = value << Fixed::bits;
}

Fixed::Fixed(float const value)
{
	double float_value = (double)value * (1 << Fixed::bits);

	if (float_value > (double)INT_MAX || float_value < (double)INT_MIN)
		throw std::invalid_argument("Error: Float to Integer overflow in conversion");
	else
		this->value = roundf(float_value);
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

bool Fixed::operator>(const Fixed &other) const { return (this->value > other.getRawBits()); }
bool Fixed::operator<(const Fixed &other) const { return (this->value < other.getRawBits()); }
bool Fixed::operator>=(const Fixed &other) const { return (this->value >= other.getRawBits()); }
bool Fixed::operator<=(const Fixed &other) const { return (this->value <= other.getRawBits()); }
bool Fixed::operator==(const Fixed &other) const { return (this->value == other.getRawBits()); }
bool Fixed::operator!=(const Fixed &other) const { return (this->value != other.getRawBits()); }

Fixed Fixed::operator+(const Fixed &other) const
{
	return Fixed(this->toFloat() + other.toFloat());
}

Fixed Fixed::operator-(const Fixed &other) const
{
	return Fixed(this->toFloat() - other.toFloat());
}

Fixed Fixed::operator*(const Fixed &other) const
{
	return Fixed(this->toFloat() * other.toFloat());
}

Fixed Fixed::operator/(const Fixed &other) const
{
	return Fixed(this->toFloat() / other.toFloat());
}
