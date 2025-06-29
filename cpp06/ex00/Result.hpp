#ifndef RESULT_HPP
#define RESULT_HPP

#include <iostream>

typedef enum t_err
{
	NO_ERROR,
	OUT_OF_RANGE,
	OUT_OF_RANGE_NEGATIVE,
	OUT_OF_RANGE_POSITIVE,
	INVALID_ARGUMENT,
	NOT_PRINTABLE_CHAR,
	UNDEFINED_ERROR
} e_err;

template <typename T, typename E>
class Result
{
public:
	Result(void) : _value(T()), _error(E()) {};
	Result(T value, E error) : _value(value), _error(error) {};
	Result(E error) : _value(T()), _error(error) {};
	Result(const Result &src) : _value(src._value), _error(src._error) {};
	Result &operator=(const Result &src)
	{
		if (this != &src)
		{
			this->_value = src._value;
			this->_error = src._error;
		}
		return (*this);
	}
	~Result(void)
	{
		return;
	}

	T unwrap() const
	{
		return (this->_value);
	}

	E error_kind() const
	{
		return (this->_error);
	}

private:
	T _value;
	E _error;
};

#endif
