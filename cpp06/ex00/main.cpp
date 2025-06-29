#include <cstring>
#include <iostream>
#include <iomanip>

#include "Result.hpp"
#include "ScalarConverter.hpp"

static void print_usage()
{
	std::cout << "Usage: ./convert [value]" << std::endl;
	std::cout << "Usage: ./convert [value] [typename]" << std::endl;
}

static void print_intline(const t_all_results &result)
{
	std::cout << "int:\t";
	switch (result.intResult.error_kind())
	{
	case NO_ERROR:
		std::cout << result.intResult.unwrap();
		break;
	case INVALID_ARGUMENT:
		std::cout << "impossible";
		break;
	case OUT_OF_RANGE:
		std::cout << "impossible";
		break;
	default:
		std::cout << "undefined error";
	}
	std::cout << std::endl;
}

static void print_charline(const t_all_results &result)
{
	std::cout << "char:\t";
	switch (result.charResult.error_kind())
	{
	case NO_ERROR:
		std::cout << "'" << result.charResult.unwrap() << "'";
		break;
	case NOT_PRINTABLE_CHAR:
		std::cout << "Non displayable";
		break;
	case INVALID_ARGUMENT:
		std::cout << "impossible";
		break;
	case OUT_OF_RANGE:
		std::cout << "impossible";
		break;
	default:
		std::cout << "undefined error";
		break;
	}
	std::cout << std::endl;
}

static void print_floatline(const t_all_results &result)
{
	std::cout << "float:\t";
	switch (result.floatResult.error_kind())
	{
	case NO_ERROR:
		std::cout << std::fixed << std::setprecision(1) << result.floatResult.unwrap();
		break;
	case INVALID_ARGUMENT:
		std::cout << "nan";
		break;
	case OUT_OF_RANGE_NEGATIVE:
		std::cout << "-inf";
		break;
	case OUT_OF_RANGE_POSITIVE:
		std::cout << "+inf";
		break;
	default:
		std::cout << "undefined error";
	}
	std::cout << "f" << std::endl;
}

static void print_doubleline(const t_all_results &result)
{
	std::cout << "double:\t";
	switch (result.doubleResult.error_kind())
	{
	case NO_ERROR:
		std::cout << std::fixed << std::setprecision(1) << result.doubleResult.unwrap();
		break;
	case INVALID_ARGUMENT:
		std::cout << "nan";
		break;
	case OUT_OF_RANGE_NEGATIVE:
		std::cout << "-inf";
		break;
	case OUT_OF_RANGE_POSITIVE:
		std::cout << "+inf";
		break;
	default:
		std::cout << "undefined error";
	}
	std::cout << std::endl;
}

// std::numeric_limits,atoi,strtol were introduced in c++98,
// std::isnan(), std::isinf(), std::stoi(), std::stof() were introduced in c++11
int main(int argc, char **argv)
{
	if (argc == 1 || argc >= 4)
	{
		print_usage();
		return 0;
	}
	const std::string input = argv[1];

	t_all_results result;
	result = ScalarConverter::convert(input);

	if (argc == 2 || strcmp(argv[2], "char") == 0)
		print_charline(result);
	if (argc == 2 || strcmp(argv[2], "int") == 0)
		print_intline(result);
	if (argc == 2 || strcmp(argv[2], "float") == 0)
		print_floatline(result);
	if (argc == 2 || strcmp(argv[2], "double") == 0)
		print_doubleline(result);
	return (0);
}
