#include "Point.hpp"
#include <iostream>

Point::Point(void) : _x(0), _y(0)
{
	return;
}

Point::Point(float x, float y) : _x(x), _y(y)
{
	return;
}

Point::Point(const Fixed &x, const Fixed &y) : _x(x), _y(y)
{
	return;
}

Point::Point(const Point &rhs)
{
	*this = rhs;
}

Point &Point::operator=(const Point &rhs)
{
	this->_x = rhs._x;
	this->_y = rhs._y;

	return *(this);
}

Point::~Point(void)
{
	// std::cout << "Destructed💥" << std::endl;
	return;
}

Point Point::operator-(const Point &rhs) const
{

	return Point(this->_x - rhs._x, this->_y - rhs._y);
}

Fixed Point::get_x(void) const
{
	return this->_x;
}

Fixed Point::get_y(void) const
{
	return this->_y;
}

std::ostream &operator<<(std::ostream &o, const Point &rhs)
{
	o << "(" << rhs.get_x() << ", " << rhs.get_y() << ")";
	return o;
}

Fixed det(const Point &lhs, const Point &rhs)
{
	return lhs.get_x() * rhs.get_y() - lhs.get_y() * rhs.get_x();
}
