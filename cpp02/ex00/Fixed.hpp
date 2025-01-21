#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
class Fixed
{

public:
	Fixed(void);						// default constructor
	Fixed(const Fixed &src);			// copy constructor
	Fixed &operator=(const Fixed &src); // copy assignment operator
	~Fixed(void);						// destructor

	int getRawBits(void) const;
	void setRawBits(int const raw);

private:
	int _fixedNumber;
	static const int _FRACTIONBITS = 8;
};
#endif
