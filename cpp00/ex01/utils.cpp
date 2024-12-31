#include <iostream>
#include <string>

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

__attribute__((destructor)) void end()
{
	system("leaks phonebook");
}
