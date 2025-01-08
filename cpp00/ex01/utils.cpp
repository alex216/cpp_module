#include <iostream>
#include <string>
#include <cstdlib>

void err(const std::string &msg)
{
	std::cerr << msg << std::endl;
	exit(1);
}

std::string truncate(std::string str)
{
	if (str.length() > 10)
		return str.substr(0, 10 - 1) + ".";
	return str;
}

std::string question(std::string question)
{
	std::string input;
	std::cout << question;
	std::getline(std::cin, input);
	if (std::cin.fail() || std::cin.eof())
		exit(1);
	return input;
}

bool is_valid_phone_number(const std::string &phone_number)
{
	if (phone_number.empty())
		return false;

	for (size_t i = 0; i < phone_number.length(); i++)
	{
		if (!std::isdigit(phone_number[i]))
			return false;
	}
	return true;
}

#if defined(__APPLE__)
__attribute__((destructor)) void end()
{
	system("leaks phonebook");
}
#endif
