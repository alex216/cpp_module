#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

#ifdef __APPLE__
__attribute__((destructor)) static void destructor()
{
	if (system("leaks -q main > /dev/null 2> /dev/null"))
		system("leaks -q main");
}
#endif

void testShrubberyCreationForm()
{
	std::cout << "[Create Form]" << std::endl;
	ShrubberyCreationForm form("F1"); // target
	std::cout << form << std::endl;

	std::cout << "[Create Bureaucrat with grade 145]" << std::endl;
	Bureaucrat bureaucrat("B1", 145);
	std::cout << bureaucrat << std::endl;

	std::cout << "[Sign form]" << std::endl;
	bureaucrat.signForm(form);
	std::cout << form << std::endl;

	std::cout << "[B1 cannot execute form]" << std::endl;
	bureaucrat.executeForm(form);

	std::cout << "[Create Bureaucrat with grade 137]" << std::endl;
	Bureaucrat bureaucrat2("B2", 137);
	std::cout << bureaucrat2 << std::endl;

	std::cout << "[B2 executes form]" << std::endl;
	bureaucrat2.executeForm(form);

	std::cout << "[Execute form again]" << std::endl;
	bureaucrat2.executeForm(form);
}

void testRobotomyRequestForm()
{
	std::cout << "[Create Form]" << std::endl;
	RobotomyRequestForm form("F1"); // target
	std::cout << form << std::endl;

	std::cout << "[Create Bureaucrat with grade 72]" << std::endl;
	Bureaucrat bureaucrat("B1", 72);
	std::cout << bureaucrat << std::endl;

	std::cout << "[Sign form]" << std::endl;
	bureaucrat.signForm(form);
	std::cout << form << std::endl;

	std::cout << "[B1 cannot execute form]" << std::endl;
	bureaucrat.executeForm(form);

	std::cout << "[Create Bureaucrat with grade 45]" << std::endl;
	Bureaucrat bureaucrat2("B2", 45);
	std::cout << bureaucrat2 << std::endl;

	std::cout << "[B2 executes form]" << std::endl;
	bureaucrat2.executeForm(form);

	std::cout << "[Execute form again]" << std::endl;
	bureaucrat2.executeForm(form);
}

void testPresidentialPardonForm()
{
	std::cout << "[Create Form]" << std::endl;
	PresidentialPardonForm form("F1"); // target
	std::cout << form << std::endl;

	std::cout << "[Create Bureaucrat with grade 25]" << std::endl;
	Bureaucrat bureaucrat("B1", 25);
	std::cout << bureaucrat << std::endl;

	std::cout << "[Sign form]" << std::endl;
	bureaucrat.signForm(form);
	std::cout << form << std::endl;

	std::cout << "[B1 executes form]" << std::endl;
	bureaucrat.executeForm(form);

	std::cout << "[Create Bureaucrat with grade 5]" << std::endl;
	Bureaucrat bureaucrat2("B2", 5);
	std::cout << bureaucrat2 << std::endl;

	std::cout << "[B2 executes form]" << std::endl;
	bureaucrat2.executeForm(form);

	std::cout << "[Execute form again]" << std::endl;
	bureaucrat2.executeForm(form);
}

int main()
{
	std::cout << "[[Test ShrubberyCreationForm]]" << std::endl;
	testShrubberyCreationForm();

	std::cout << std::endl;
	std::cout << "[[Test RobotomyRequestForm]]" << std::endl;
	testRobotomyRequestForm();

	std::cout << std::endl;
	std::cout << "[[Test PresidentialPardonForm]]" << std::endl;
	testPresidentialPardonForm();
}
