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
		throw std::overflow_error("Error: Integer overflow in conversion");
	else
		this->value = value << Fixed::bits;
}

Fixed::Fixed(float const value)
{
	double float_value = (double)value * (1 << Fixed::bits);

	if (float_value > (double)INT_MAX || float_value < (double)INT_MIN)
		throw std::overflow_error("Error: Float to Integer overflow in conversion");
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
	Fixed result;
	long temp = (long)this->value + (long)other.getRawBits();
	if (temp > INT_MAX || temp < INT_MIN)
		throw std::overflow_error("Addition overflow");
	result.setRawBits((int)temp);
	return result;
}

Fixed Fixed::operator-(const Fixed &other) const
{
	Fixed result;
	long temp = (long)this->value - (long)other.getRawBits();
	if (temp > INT_MAX || temp < INT_MIN)
		throw std::overflow_error("Subtraction overflow");
	result.setRawBits((int)temp);
	return result;
}

/*
Since fixed-point numbers store their values scaled up by a factor of 2^bits, multiplying two fixed-point numbers results in a value that's scaled up twice (effectively scaled by 2^(2*bits)).  To correct for the double scaling, the result is shifted right by Fixed::bits positions using the >> operator. This brings the decimal point back to the correct position.

EXAMPLE with factorization:
a=1.0f, b=2.0f

(a*2^8) * (b*2^8) = (a*b) * 2^(8+8), so we need to bitshift the result by 8 to right again to get the scaled value (2^(16-8))
*/
Fixed Fixed::operator*(const Fixed &other) const
{
	Fixed result;
	long temp = ((long)this->value * (long)other.getRawBits()) >> Fixed::bits;
	if (temp > INT_MAX || temp < INT_MIN)
		throw std::overflow_error("Multiplication overflow");
	result.setRawBits((int)temp);
	return result;
}

/*
Since fixed-point numbers store their values scaled up by a factor of 2^bits, dividing two fixed-point numbers results in a value that's scaled down by 2^bits. To correct for the scaling, the result is multiplied by 2^bits using the << operator. This brings the decimal point back to the correct position.

EXAMPLE with factorization:
a=1.0f, b=2.0f

(a*2^8)/(b*2^8) = (a/b) * 2^(8-8), so we need to bitshift the result by 8 to left again to get the scaled value (2^(0+8))
 */
Fixed Fixed::operator/(const Fixed &other) const
{
	if (other.getRawBits() == 0)
		throw std::runtime_error("Division by zero");
	Fixed result;
	long temp = ((long)this->value << Fixed::bits) / other.getRawBits();
	if (temp > INT_MAX || temp < INT_MIN)
		throw std::overflow_error("Division overflow");
	result.setRawBits((int)temp);
	return result;
}

Fixed &Fixed::operator++()
{
	this->value += 1;
	return *this;
}

Fixed Fixed::operator++(int)
{
	Fixed tmp(*this);
	operator++();
	return tmp;
}

Fixed &Fixed::operator--()
{
	this->value -= 1;
	return *this;
}

Fixed Fixed::operator--(int)
{
	Fixed tmp(*this);
	operator--();
	return tmp;
}

Fixed &Fixed::min(Fixed &a, Fixed &b)
{
	return (a < b) ? a : b;
}

Fixed &Fixed::max(Fixed &a, Fixed &b)
{
	return (a > b) ? a : b;
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b)
{
	return (a < b) ? a : b;
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b)
{
	return (a > b) ? a : b;
}
