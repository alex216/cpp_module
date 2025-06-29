#include "ScalarConverter.hpp"
#include "utils.hpp"

Result<char, e_err> ScalarConverter::_convertToChar(const std::string &str)
{
	// if the string is a single character and it is printable
	if (str.length() == 1 && is_printable(str[0]) && !std::isdigit(str[0]))
		return Result<char, e_err>(str[0], NO_ERROR);

	// first convert the string to an integer
	Result<int, e_err> intResult = ScalarConverter::_convertToInt(str);
	switch (intResult.error_kind())
	{
	case NO_ERROR:
		if (is_printable(intResult.unwrap()))
			return Result<char, e_err>(static_cast<char>(intResult.unwrap()), NO_ERROR);
		else
			return Result<char, e_err>(NOT_PRINTABLE_CHAR);
	case INVALID_ARGUMENT:
		return Result<char, e_err>(INVALID_ARGUMENT);
	case OUT_OF_RANGE:
		return Result<char, e_err>(OUT_OF_RANGE);
	default:
		return Result<char, e_err>(UNDEFINED_ERROR);
	}
}

Result<int, e_err> ScalarConverter::_convertToInt(const std::string &str)
{
	try
	{
		return Result<int, e_err>(my_stoi(str.c_str()), NO_ERROR);
	}
	catch (const std::invalid_argument &e)
	{
		return Result<int, e_err>(INVALID_ARGUMENT);
	}
	catch (const std::out_of_range &e)
	{
		return Result<int, e_err>(OUT_OF_RANGE);
	}
	return Result<int, e_err>(UNDEFINED_ERROR);
}

Result<float, e_err> ScalarConverter::_convertToFloat(const std::string &str)
{
	float value;

	value = 0.0f; // Initialize value to avoid potential uninitialized variable warnings
	try
	{
		value = my_stof(str.c_str());
		return Result<float, e_err>(value, NO_ERROR);
	}
	catch (const std::invalid_argument &e)
	{
		return Result<float, e_err>(INVALID_ARGUMENT);
	}
	catch (const std::out_of_range &e)
	{
		if (str.c_str()[0] == '-')
			return Result<float, e_err>(value, OUT_OF_RANGE_NEGATIVE);
		else
			return Result<float, e_err>(value, OUT_OF_RANGE_POSITIVE);
	}
	return Result<float, e_err>(UNDEFINED_ERROR);
}

Result<double, e_err> ScalarConverter::_convertToDouble(const std::string &str)
{
	double value;

	value = 0.0f; // Initialize value to avoid potential uninitialized variable warnings
	try
	{
		value = my_stod(str.c_str());
		return Result<double, e_err>(value, NO_ERROR);
	}
	catch (const std::invalid_argument &e)
	{
		return Result<double, e_err>(INVALID_ARGUMENT);
	}
	catch (const std::out_of_range &e)
	{
		if (str.c_str()[0] == '-')
			return Result<double, e_err>(value, OUT_OF_RANGE_NEGATIVE);
		else
			return Result<double, e_err>(value, OUT_OF_RANGE_POSITIVE);
	}
	return Result<double, e_err>(UNDEFINED_ERROR);
}

t_all_results ScalarConverter::convert(const std::string &input)
{
	t_all_results answer;

	answer.charResult = ScalarConverter::_convertToChar(input);
	answer.intResult = ScalarConverter::_convertToInt(input);
	answer.floatResult = ScalarConverter::_convertToFloat(input);
	answer.doubleResult = ScalarConverter::_convertToDouble(input);

	return answer;
}
