#include "Intern.hpp"

typedef AForm* (Intern::*FormCreater)(const std::string &target);

Intern::Intern(void)
{
	return;
}

Intern::Intern(const Intern &src)
{
	*this = src;
}

Intern &Intern::operator=(const Intern &src)
{
	if (this != &src)
	{
		*this = src;
	}
	return *(this);
}

Intern::~Intern(void)
{
	return;
}

AForm *Intern::makeForm(const std::string &formName, const std::string &target)
{
	const std::string FormArray[3] =
	{
		"ShrubberyCreationForm",
		"RobotomyRequestForm",
		"PresidentialPardonForm"
	};

	const FormCreater FuncArray[3] =
	{
		&Intern::createSForm,
		&Intern::createRForm,
		&Intern::createPForm
	};

	for (int i = 0; i < 3; i++)
	{
		if (FormArray[i] == formName)
		{
			std::cout << "Intern creates " << formName << std::endl;
			return (this->*FuncArray[i])(target);
		}
	};
	std::cout << "Intern cannot create " << formName << std::endl;
	return NULL;
}

AForm *Intern::createPForm(const std::string &target)
{
	return new PForm(target);
}

AForm *Intern::createRForm(const std::string &target)
{
	return new RForm(target);
}

AForm *Intern::createSForm(const std::string &target)
{
	return new SForm(target);
}
