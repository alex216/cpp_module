#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include <iostream>
#include <fstream>

#include "AForm.hpp"

class Bureaucrat;

class ShrubberyCreationForm : public AForm
{
public:
	ShrubberyCreationForm(void);
	ShrubberyCreationForm(const std::string &target);
	ShrubberyCreationForm(const ShrubberyCreationForm &src);
	ShrubberyCreationForm &operator=(const ShrubberyCreationForm &src);
	virtual ~ShrubberyCreationForm(void);

	const std::string &getTarget(void) const;

	virtual void execute(const Bureaucrat &executor) const;

private:
	static const int _MinGradeToSign = 145;
	static const int _MinGradeToExec = 137;

	std::string _target;
};
#endif
