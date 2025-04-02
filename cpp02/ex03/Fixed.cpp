#include "Fixed.hpp"
#include <iostream>

Fixed::Fixed(void) : _fixedNumber(0)
{
	return;
}

Fixed::Fixed(const Fixed &src)
{
	// std::cout << "[Copy constructor]\t\tcalled" << std::endl;
	*this = src;
}

Fixed &Fixed::operator=(const Fixed &src)
{
	// std::cout << "[Copy assignment operator]\tcalled" << std::endl;
	this->setRawBits(src.getRawBits());
	return *(this);
}

Fixed::~Fixed(void)
{
	// std::cout << "💥Destructed" << std::endl;
	return;
}

// ex01
// Q8 format loses precision for fractional values when the mantissa exceeds 256.
Fixed::Fixed(const float float_number)
{
	union
	{
		float f;
		unsigned int i;
	} num;

	num.f = float_number;

	unsigned int sign = (num.i >> 31 & 1);
	unsigned int exponent = ((num.i >> 23) & 0xFF);
	unsigned int mantissa = ((num.i >> (23 - _FRACTIONBITS)) & 0xFF) | ((num.i >> (23 - _FRACTIONBITS - 1)) & 1);

	int result = 0;
	result |= sign << (sizeof(int) * 8 - 1);
	result |= exponent << _FRACTIONBITS;
	result |= mantissa;

	this->setRawBits(result);
}

float Fixed::toFloat(void) const
{
	int fixed_float = this->getRawBits();

	int sign = (fixed_float >> (sizeof(int) * 8 - 1)) & 1;
	int exponent = (fixed_float >> _FRACTIONBITS) & 0xFF;
	int mantissa = fixed_float & 0xFF;

	union
	{
		float f;
		unsigned int i;
	} num;

	num.f = 0;
	num.i |= sign << (sizeof(int) * 8 - 1);
	num.i |= exponent << 23;
	num.i |= mantissa << (23 - _FRACTIONBITS);

	return num.f;
}

Fixed::Fixed(const int decimal_part)
{
	Fixed tmp = Fixed(float(decimal_part));
	this->setRawBits(tmp.getRawBits());
}

int Fixed::toInt(void) const
{
	return (int)this->toFloat();
}

std::ostream &operator<<(std::ostream &o, const Fixed &rhs)
{
	o << rhs.toFloat();
	return o;
}
// ex01

// ex02
bool Fixed::operator>(const Fixed &rhs) const
{
	return this->toFloat() > rhs.toFloat();
}

bool Fixed::operator<(const Fixed &rhs) const
{
	return this->toFloat() < rhs.toFloat();
}

bool Fixed::operator>=(const Fixed &rhs) const
{
	return !operator<(rhs);
}

bool Fixed::operator<=(const Fixed &rhs) const
{
	return !operator>(rhs);
}

bool Fixed::operator==(const Fixed &rhs) const
{
	return this->getRawBits() == rhs.getRawBits();
}

bool Fixed::operator!=(const Fixed &rhs) const
{
	return this->getRawBits() != rhs.getRawBits();
}

Fixed Fixed::operator+(const Fixed &rhs) const
{
	return Fixed(this->toFloat() + rhs.toFloat());
}

Fixed Fixed::operator-(const Fixed &rhs) const
{
	return Fixed(this->toFloat() - rhs.toFloat());
}

Fixed Fixed::operator*(const Fixed &rhs) const
{
	return Fixed(this->toFloat() * rhs.toFloat());
}

Fixed Fixed::operator/(const Fixed &rhs) const
{
	return Fixed(this->toFloat() / rhs.toFloat());
}

Fixed &Fixed::operator++() // pre
{
	this->_fixedNumber++;
	return *this;
}

Fixed Fixed::operator++(int) // post
{
	Fixed tmp(*this);
	this->_fixedNumber++;
	return tmp;
}

Fixed &Fixed::operator--() // pre
{
	this->_fixedNumber--;
	return *this;
}

Fixed Fixed::operator--(int) // post
{
	Fixed tmp(*this);
	this->_fixedNumber--;
	return tmp;
}

// static funcs
Fixed &Fixed::min(Fixed &a, Fixed &b)
{
	if (a < b)
		return a;
	return b;
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b)
{
	if (a < b)
		return a;
	return b;
}

Fixed &Fixed::max(Fixed &a, Fixed &b)
{
	if (a > b)
		return a;
	return b;
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b)
{
	if (a > b)
		return a;
	return b;
}
// ex02

int Fixed::getRawBits(void) const
{
	return this->_fixedNumber;
}

void Fixed::setRawBits(int const raw)
{
	this->_fixedNumber = raw;
}
