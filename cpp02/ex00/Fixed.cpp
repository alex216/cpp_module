#include "Fixed.hpp"

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

int Fixed::getRawBits(void) const
{
	std::cout << "[getRawBits member function]\tcalled" << std::endl;
	return this->_fixedNumber;
}

void Fixed::setRawBits(int const raw)
{
	this->_fixedNumber = raw;
}
