#ifndef DATA_HPP
#define DATA_HPP

#include <iostream>

class Data
{
public:
	Data(void);
	Data(const Data &src);
	Data &operator=(const Data &src);
	~Data(void);

	Data(const std::string &name, const int &age);

	const std::string& getName(void) const;
	const int& getAge(void) const;

private:
	std::string _name;
	int _age;

};
#endif
