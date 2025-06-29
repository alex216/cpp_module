#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include <iostream>
#include <cstdlib>

#include "AForm.hpp"

class Bureaucrat;

class RobotomyRequestForm : public AForm
{
public:
	RobotomyRequestForm(void);
	RobotomyRequestForm(const std::string &target);
	RobotomyRequestForm(const RobotomyRequestForm &src);
	RobotomyRequestForm &operator=(const RobotomyRequestForm &src);
	virtual ~RobotomyRequestForm(void);

	const std::string &getTarget(void) const;

	virtual void execute(const Bureaucrat &executor) const;

private:
	static const int _MinGradeToSign = 72;
	static const int _MinGradeToExec = 45;

	std::string _target;
};
#endif
