#include <iostream>

#include "Bureaucrat.hpp"

#ifdef __APPLE__
__attribute__((destructor)) static void destructor()
{
	if (system("leaks -q main > /dev/null 2> /dev/null"))
		system("leaks -q main");
}
#endif

int main()
{
	// 	Grade is too high
	try
	{
		Bureaucrat top_hacker("Top Hacker", 0);
	}
	catch (Bureaucrat::GradeTooHighException &e)
	{
		std::cout << e.what() << std::endl;
	}
	// Grade is too low
	try
	{
		Bureaucrat bottom_hacker("Bottom Hacker", 151);
	}
	catch (Bureaucrat::GradeTooLowException &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;

	Bureaucrat taro; // Default bureaucrat grade        150
	std::cout << taro << std::endl;
	taro.incrementGrade(); // Default bureaucrat grade        149
	std::cout << taro << std::endl;
	taro.decrementGrade(); // Default bureaucrat grade        150
	std::cout << taro << std::endl;
	std::cout << std::endl;

	Bureaucrat top("Top", Bureaucrat::HIGHEST_GRADE);
	std::cout << top << std::endl;
	try
	{
		top.incrementGrade();
	}
	catch (Bureaucrat::GradeTooHighException &e)
	{
		// Grade is too high
		std::cout << e.what() << std::endl;
	}
	std::cout << top << std::endl;
	std::cout << std::endl;

	Bureaucrat bottom("Bottom", Bureaucrat::LOWEST_GRADE);
	std::cout << bottom << std::endl;
	try
	{
		bottom.decrementGrade();
	}
	catch (Bureaucrat::GradeTooLowException &e)
	{
		// Grade is too low
		std::cerr << e.what() << std::endl;
	}
	std::cout << bottom << std::endl;
	std::cout << std::endl;
}
