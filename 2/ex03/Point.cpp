#include "Point.hpp"

Point::Point() : _x(0), _y(0) {}

Point::Point(const Point &other) : _x(other._x), _y(other._y) {}

Point &Point::operator=(const Point &other)
{
	(void)other;
	throw std::runtime_error("Error: Cannot assign to a const object");
}

Point::~Point() {}

Point::Point(const float x, const float y) : _x(x), _y(y) {}

Fixed Point::getX() const
{
	return _x;
}

Fixed Point::getY() const
{
	return _y;
}
