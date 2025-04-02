#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cstdlib>

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

	// ex02
	bool operator>(const Fixed &rhs) const;
	bool operator<(const Fixed &rhs) const;
	bool operator>=(const Fixed &rhs) const;
	bool operator<=(const Fixed &rhs) const;
	bool operator==(const Fixed &rhs) const;
	bool operator!=(const Fixed &rhs) const;

	Fixed operator+(const Fixed &rhs) const;
	Fixed operator-(const Fixed &rhs) const;
	Fixed operator*(const Fixed &rhs) const;
	Fixed operator/(const Fixed &rhs) const;

	Fixed &operator++();   // pre
	Fixed operator++(int); // post
	Fixed &operator--();   // pre
	Fixed operator--(int); // post

	static Fixed &min(Fixed &a, Fixed &b);
	static const Fixed &min(const Fixed &a, const Fixed &b);
	static Fixed &max(Fixed &a, Fixed &b);
	static const Fixed &max(const Fixed &a, const Fixed &b);
	// ex02

	int getRawBits(void) const;
	void setRawBits(int const raw);

private:
	int _fixedNumber;
	static const int _FRACTIONBITS = 8;
	static const int LARGEINT = 1 << Fixed::_FRACTIONBITS;
};

std::ostream &operator<<(std::ostream &o, const Fixed &rhs);
#endif
