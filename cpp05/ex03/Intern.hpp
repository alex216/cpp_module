#ifndef INTERN_HPP
#define INTERN_HPP

#include <iostream>

#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

typedef PresidentialPardonForm PForm;
typedef RobotomyRequestForm RForm;
typedef ShrubberyCreationForm SForm;

class Intern
{
public:
	Intern(void);
	Intern(const Intern &src);
	Intern &operator=(const Intern &src);
	virtual ~Intern(void);

	AForm *makeForm(const std::string &formName, const std::string &target);

private:
	AForm *createPForm(const std::string &target);
	AForm *createRForm(const std::string &target);
	AForm *createSForm(const std::string &target);
};

#endif
