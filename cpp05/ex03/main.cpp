#include <iostream>

#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

__attribute__((destructor)) static void destructor()
{
	if (system("leaks -q main > /dev/null 2> /dev/null"))
		system("leaks -q main");
}

void createFormAndExecute(const std::string &formName, const std::string &target)
{
	Intern intern;
	AForm *form = intern.makeForm(formName, target);
	if (!form)
		return;
	std::cout << *form << std::endl;

	std::cout << "Signs and executes form" << std::endl;
	Bureaucrat bureaucrat("B1", 1);
	bureaucrat.signForm(*form);
	bureaucrat.executeForm(*form);

	delete form;
}

int main()
{
	std::cout << "[Test ShrubberyCreationForm]" << std::endl;
	createFormAndExecute("ShrubberyCreationForm", "F1");

	std::cout << std::endl;
	std::cout << "[Test RobotomyRequestForm]" << std::endl;
	createFormAndExecute("RobotomyRequestForm", "F2");

	std::cout << std::endl;
	std::cout << "[Test PresidentialPardonForm]" << std::endl;
	createFormAndExecute("PresidentialPardonForm", "F3");

	std::cout << std::endl;
	std::cout << "[Test Invalid Form]" << std::endl;
	createFormAndExecute("invalid form", "F4");
}
