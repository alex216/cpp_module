#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"
#include <iostream>

class Point
{
public:
	Point(void);
	Point(const Point &src);			// copy constructor
	Point &operator=(const Point &rhs); // copy assignment operator
	~Point(void);

	Point(float, float);
	Point(const Fixed &x, const Fixed &y);

	Point operator-(const Point &rhs) const;

	Fixed get_x(void) const;
	Fixed get_y(void) const;

private:
	Fixed _x;
	Fixed _y;
};

std::ostream &operator<<(std::ostream &o, const Point &rhs);
Fixed det(const Point &lhs, const Point &rhs);

#endif
