#include "Fixed.hpp"
#include <iostream>

Fixed::Fixed(void) : _fixedNumber(0)
{
	std::cout << "[Default constructor]\t\tcalled" << std::endl;
	return;
}

Fixed::Fixed(const Fixed &src)
{
	std::cout << "[Copy constructor]\t\tcalled" << std::endl;
	*this = src;
}

Fixed &Fixed::operator=(const Fixed &src)
{
	std::cout << "[Copy assignment operator]\tcalled" << std::endl;
	this->setRawBits(src.getRawBits());
	return *(this);
}

Fixed::~Fixed(void)
{
	std::cout << "💥Destructed" << std::endl;
	return;
}

// ex01
Fixed::Fixed(const int decimal_part)
{
	std::cout << "[Int constructor]\t\tcalled" << std::endl;
	// overflow overlooked
	this->setRawBits(decimal_part << _FRACTIONBITS);
}

Fixed::Fixed(const float float_num)
{
	std::cout << "[Float constructor]\t\tcalled" << std::endl;
	// overflow overlooked
	int raw = roundf(float_num * (1 << _FRACTIONBITS));
	this->setRawBits(raw);
}

float Fixed::toFloat(void) const
{
	return static_cast<float>(this->_fixedNumber) / (1 << _FRACTIONBITS);
}

int Fixed::toInt(void) const
{
	return this->_fixedNumber >> _FRACTIONBITS;
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
