#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(void) :
	AForm("Default PresidentialPardonForm",
		PresidentialPardonForm::_MinGradeToSign,
		PresidentialPardonForm::_MinGradeToExec),
	_target("default")
{
	return;
}

PresidentialPardonForm::PresidentialPardonForm(const std::string &target) :
	AForm("Default PresidentialPardonForm",
		PresidentialPardonForm::_MinGradeToSign,
		PresidentialPardonForm::_MinGradeToExec),
	_target(target)
{
	return;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &src) : 
	AForm(src),
	_target(src.getTarget())
{
	return;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &src)
{
	if (this != &src)
	{
		AForm::operator=(src);
		this->_target = src.getTarget();
	}
	return *(this);
}

PresidentialPardonForm::~PresidentialPardonForm(void)
{
	return;
}

const std::string &PresidentialPardonForm::getTarget(void) const
{
	return this->_target;
}

void PresidentialPardonForm::execute(const Bureaucrat &executor) const
{
	if (executor.getGrade() > this->getMinGradeToExec())
		throw AForm::NotEnoughGradeToExecException();
	if (!this->getIsSigned())
		throw AForm::NotSignedException();

	std::cout << this->getTarget() << " has been pardoned by Zafod Beeblebrox" << std::endl;

	return;
}
