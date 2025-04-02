#include "Fixed.hpp"

#ifdef __APPLE__
__attribute__((destructor)) static void destructor()
{
	if (system("leaks -q Fixed > /dev/null 2> /dev/null"))
		system("leaks -q Fixed");
}
#endif

void title(std::string str)
{
	std::cout << std::endl
			  << "#### " << str << " ####" << std::endl;
}

void printfloatbits(float f)
{
	unsigned int *ptr = reinterpret_cast<unsigned int *>(&f);
	std::ostringstream label;
	label << "Float bits of " << f;
	std::cout << std::left << std::setw(30) << label.str() << " : ";
	for (int i = 31; i >= 0; i--)
	{
		std::cout << ((*ptr >> i) & 1);
		if (i == 31 || i == 23)
			std::cout << " ";
	}
	std::cout << std::endl;
}

void printfixedbits(Fixed f)
{
	std::ostringstream label;
	label << "Fixed bits of " << f;
	std::cout << std::left << std::setw(30) << label.str() << " : ";
	bool is_zero = (f.getRawBits() == 0);
	for (int i = 31; i >= 0; i--)
	{
		if (is_zero)
			std::cout << "\033[31m"; // Red color
		std::cout << ((f.getRawBits() >> i) & 1);
		if (is_zero)
			std::cout << "\033[0m"; // Reset color
		if (i == 31 || i == 23)
			std::cout << " ";
	}
	std::cout << std::endl;
}

struct FloatWithName
{
	const char *name;
	float value;
};

struct IntWithName
{
	const char *name;
	int value;
};

int main(void)
{
	std::cout << "Int type size : " << sizeof(int) << "bytes" << std::endl;

	std::cout << std::endl
			  << "[test float]" << std::endl;

	float a_little_small_number = 0.001953125f;	  // 2^(-8-1)
	float very_small_number = ldexpf(1.0f, -135); // 2^(-126-8-1)

	FloatWithName floatArray[] = {
		{"prev of 2^(-135)", nextafterf(very_small_number, -1)},
		{"2^(-135)", very_small_number},
		{"prev of 2^(-9)", nextafterf(a_little_small_number, -1)},
		{"2^(-9)", a_little_small_number},
		{"255.3", 255.3f},
		{"255.7", 255.7f},
		{"2^(32-9)", (float)pow(2, 23)},
		{"2^(32-8)", (float)pow(2, 24)}};

	const unsigned int arraySize = sizeof(floatArray) / sizeof(FloatWithName);
	for (unsigned int i = 0; i < arraySize; i++)
	{
		std::cout << floatArray[i].name << " = "
				  << std::setprecision(10) << floatArray[i].value << std::endl;
		printfloatbits(floatArray[i].value);
		Fixed fixed_f(floatArray[i].value);
		printfixedbits(fixed_f);
		std::cout << std::endl;
	}

	std::cout << std::endl
			  << "[test int]" << std::endl;

	IntWithName intArray[] = {
		{"-2^23 - 1", -(int)pow(2, 23) - 1},
		{"-2^23", -(int)pow(2, 23)},
		{"0", 0},
		{"1", 1},
		{"2^9 - 1", (int)pow(2, 9) - 1},
		{"2^23 - 1", (int)pow(2, 23) - 1},
		{"2^23", (int)pow(2, 23)},
		{"INT_MAX", 2147483647}};

	for (unsigned int i = 0; i < sizeof(intArray) / sizeof(IntWithName); i++)
	{
		std::cout << intArray[i].name << " = " << intArray[i].value << std::endl;
		Fixed fixed_i(intArray[i].value);
		printfixedbits(fixed_i);
		std::cout << "result: ";
		if (fixed_i.toInt() == intArray[i].value)
			std::cout << "\033[32mOK\033[0m"; // 32 is green
		else
		{
			std::cout << "\033[31mKO\033[0m"; // 31 is red
			std::cout << " ( " << fixed_i.toInt() << " )";
		}
		std::cout << std::endl
				  << std::endl;
	}

	// safe to use between -512 to 512
	for (int i = -pow(2, 9) - 6; i <= pow(2, 9) + 6; i++)
	{
		Fixed fixed_i(i);
		if (fixed_i.toInt() == i)
			std::cout << "\033[32mo\033[0m"; // 32 is green
		else
		{
			// std::cout << i;
			std::cout << "\033[31mx\033[0m"; // 31 is red
											 // break;
		}
	}
	std::cout << std::endl;

	Fixed a;
	Fixed const b(10);
	Fixed const c(42.42f);
	Fixed const d(b);
	a = Fixed(1234.4321f);
	std::cout << "a is " << a << std::endl;
	std::cout << "b is " << b << std::endl;
	std::cout << "c is " << c << std::endl;
	std::cout << "d is " << d << std::endl;
	std::cout << "a is " << a.toInt() << " as integer" << std::endl;
	std::cout << "b is " << b.toInt() << " as integer" << std::endl;
	std::cout << "c is " << c.toInt() << " as integer" << std::endl;
	std::cout << "d is " << d.toInt() << " as integer" << std::endl;

	return 0;
}
