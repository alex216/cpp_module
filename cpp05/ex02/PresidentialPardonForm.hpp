#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include <iostream>

#include "AForm.hpp"

class Bureaucrat;

class PresidentialPardonForm : public AForm
{
public:
	PresidentialPardonForm(void);
	PresidentialPardonForm(const std::string &target);
	PresidentialPardonForm(const PresidentialPardonForm &src);
	PresidentialPardonForm &operator=(const PresidentialPardonForm &src);
	virtual ~PresidentialPardonForm(void);

	const std::string &getTarget(void) const;

	virtual void execute(const Bureaucrat &executor) const;

private:
	static const int _MinGradeToSign = 25;
	static const int _MinGradeToExec = 5;

	std::string _target;
};
#endif
