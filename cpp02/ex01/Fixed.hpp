#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed
{

public:
	Fixed(void);						// default constructor
	Fixed(const Fixed &rhs);			// copy constructor
	Fixed &operator=(const Fixed &rhs); // copy assignment operator
	~Fixed(void);						// destructor

	// ex01
	Fixed(const int);
	Fixed(const float);
	float toFloat(void) const;
	int toInt(void) const;
	// ex01

	int getRawBits(void) const;
	void setRawBits(int const raw);

private:
	int _fixedNumber;
	static const int _FRACTIONBITS = 8;
};
std::ostream &operator<<(std::ostream &o, const Fixed &rhs);
#endif
