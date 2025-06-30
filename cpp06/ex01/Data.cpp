#include "Data.hpp"

Data::Data(void) : _name(""), _age(0)
{
	return;
}

Data::Data(const Data &src) : _name(src._name), _age(src._age)
{
	return;
}

Data &Data::operator=(const Data &src)
{
	if (this != &src)
	{
		this->_name = src._name;
		this->_age = src._age;
	}
	return *(this);
}

Data::~Data(void)
{
	return;
}

Data::Data(const std::string &name, const int &age) : _name(name), _age(age)
{
	return;
}

const std::string &Data::getName(void) const
{
	return _name;
}

const int &Data::getAge(void) const
{
	return _age;
}
