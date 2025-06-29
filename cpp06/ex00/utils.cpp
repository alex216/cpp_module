#include "utils.hpp"

bool is_printable(const char c)
{
	return (c >= 32 && c <= 126);
}

// stoi were first introduced in c++11
int my_stoi(const char *str)
{
	const char *start = str;
	char *end;
	errno = 0;

	long value = std::strtol(start, &end, 10);
	// contains non-numeric characters
	if (end == str || (*end != '\0'))
	{
		throw std::invalid_argument("invalid argument");
	}
	if (errno == ERANGE || value > std::numeric_limits<int>::max() || value < std::numeric_limits<int>::min())
	{
		throw std::out_of_range("out of range");
	}
	return static_cast<int>(value);
}

// stof were first introduced in c++11
float my_stof(const char *str)
{
	const char *start = str;
	char *end;
	errno = 0;

	float value = strtof(start, &end);

	if (start == end || (*end != '\0' && strcmp(end, "f")))
	{
		throw std::invalid_argument("invalid argument");
	}
	if (errno == ERANGE)
	{
		throw std::out_of_range("out of range");
	}
	return value;
}

// stod were first introduced in c++11
double my_stod(const char *str)
{
	const char *start = str;
	char *end;
	errno = 0;

	double value = strtod(start, &end);

	if (start == end || (*end != '\0' && strcmp(end, "f")))
	{
		throw std::invalid_argument("invalid argument");
	}
	if (errno == ERANGE)
	{
		throw std::out_of_range("out of range");
	}
	return value;
}
