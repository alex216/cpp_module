#include <iostream>

int main()
{
	std::string string = "HI THIS IS BRAIN";
	std::string &stringREF = string;
	std::string *stringPTR = &string;

	std::cout << "The memory address of the string.\t" << &string << std::endl;
	std::cout << "The memory address held by stringPTR.\t" << stringPTR << std::endl;
	std::cout << "The memory address held by stringREF.\t" << &stringREF << std::endl;

	std::cout << "The value of the string variable.\t" << string << std::endl;
	std::cout << "The value pointed to by stringPTR.\t" << *stringPTR << std::endl;
	std::cout << "The value pointed to by stringREF.\t" << stringREF << std::endl;
}
