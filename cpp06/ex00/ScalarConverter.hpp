#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <string>

#include "Result.hpp"

typedef struct s_all_results
{
	Result<char, e_err> charResult;
	Result<int, e_err> intResult;
	Result<float, e_err> floatResult;
	Result<double, e_err> doubleResult;
} t_all_results;

class ScalarConverter
{
public:
	static t_all_results convert(const std::string &str);

private:
	static Result<char, e_err> _convertToChar(const std::string &str);
	static Result<int, e_err> _convertToInt(const std::string &str);
	static Result<float, e_err> _convertToFloat(const std::string &str);
	static Result<double, e_err> _convertToDouble(const std::string &str);
};
#endif
