#include "bsp.hpp"

// bsp is for experiment use only, since Fixed class has many flows.
bool bsp(Point const v0, Point const b, Point const c, Point const v)
{
	const Point v1 = b - v0;
	const Point v2 = c - v0;

	Fixed m = (det(v, v2) - det(v0, v2)) / det(v1, v2);
	Fixed n = (det(v0, v1) - det(v, v1)) / det(v1, v2);

	return m > Fixed(0) && n > Fixed(0) && m + n < Fixed(1);
}
