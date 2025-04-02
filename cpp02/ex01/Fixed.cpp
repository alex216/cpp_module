#include "Fixed.hpp"

#ifdef DEBUG
Fixed::Fixed() : _fixedNumber(0)
{
}

Fixed::Fixed(const int n)
{
	this->_fixedNumber = n * (1 << Fixed::_FRACTIONBITS);
}

Fixed::Fixed(const float f)
{
	this->_fixedNumber = (int)roundf(f * (1 << Fixed::_FRACTIONBITS));
}

Fixed::Fixed(const Fixed &fixed) : _fixedNumber(0)
{
	*this = fixed;
}

Fixed::~Fixed()
{
}

Fixed &Fixed::operator=(const Fixed &fixed)
{
	if (this != &fixed)
		this->_fixedNumber = fixed.getRawBits();
	return *this;
}

int Fixed::getRawBits() const
{
	return this->_fixedNumber;
}

void Fixed::setRawBits(const int r)
{
	this->_fixedNumber = r;
}

float Fixed::toFloat() const
{
	return (float)this->_fixedNumber / (1 << Fixed::_FRACTIONBITS);
}

int Fixed::toInt() const
{
	return this->_fixedNumber / (1 << Fixed::_FRACTIONBITS);
}

std::ostream &operator<<(std::ostream &os, const Fixed &fixed)
{
	os << fixed.toFloat();
	return os;
}

#else

Fixed::Fixed(void) : _fixedNumber(0)
{
	return;
}

Fixed::Fixed(const Fixed &src)
{
	*this = src;
}

Fixed &Fixed::operator=(const Fixed &src)
{
	this->setRawBits(src.getRawBits());
	return *(this);
}

Fixed::~Fixed(void)
{
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

int Fixed::getRawBits(void) const
{
	return this->_fixedNumber;
}

void Fixed::setRawBits(int const raw)
{
	this->_fixedNumber = raw;
}
#endif
