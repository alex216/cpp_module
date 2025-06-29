#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(void) : AForm("Default RobotomyRequestForm",
													   RobotomyRequestForm::_MinGradeToSign,
													   RobotomyRequestForm::_MinGradeToExec),
												 _target("default")
{
	return;
}

RobotomyRequestForm::RobotomyRequestForm(const std::string &target) : AForm("Default RobotomyRequestForm",
																			RobotomyRequestForm::_MinGradeToSign,
																			RobotomyRequestForm::_MinGradeToExec),
																	  _target(target)
{
	return;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &src) : AForm(src),
																		   _target(src.getTarget())
{
	return;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &src)
{
	if (this != &src)
	{
		AForm::operator=(src);
		this->_target = src.getTarget();
	}
	return *(this);
}

RobotomyRequestForm::~RobotomyRequestForm(void)
{
	return;
}

const std::string &RobotomyRequestForm::getTarget(void) const
{
	return this->_target;
}

void RobotomyRequestForm::execute(const Bureaucrat &executor) const
{
	if (executor.getGrade() > this->getMinGradeToExec())
		throw AForm::NotEnoughGradeToExecException();
	if (!this->getIsSigned())
		throw AForm::NotSignedException();

	std::cout << "some drilling noises" << std::endl;
	if (std::rand() % 2)
		std::cout << this->getTarget() << " has been robotomized successfully" << std::endl;
	else
		std::cout << this->getTarget() << " robotomy failed" << std::endl;

	return;
}
