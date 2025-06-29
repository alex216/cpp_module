#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(void) : AForm("Default ShrubberyCreationForm",
														   ShrubberyCreationForm::_MinGradeToSign,
														   ShrubberyCreationForm::_MinGradeToExec),
													 _target("default")
{
	return;
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target) : AForm("Default ShrubberyCreationForm",
																				ShrubberyCreationForm::_MinGradeToSign,
																				ShrubberyCreationForm::_MinGradeToExec),
																		  _target(target)
{
	return;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &src) : AForm(src),
																				 _target(src.getTarget())
{
	return;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &src)
{
	if (this != &src)
	{
		AForm::operator=(src);
		this->_target = src.getTarget();
	}
	return *(this);
}

ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
	return;
}

const std::string &ShrubberyCreationForm::getTarget(void) const
{
	return this->_target;
}

void ShrubberyCreationForm::execute(const Bureaucrat &executor) const
{
	if (executor.getGrade() > this->getMinGradeToExec())
		throw AForm::NotEnoughGradeToExecException();
	if (!this->getIsSigned())
		throw AForm::NotSignedException();

	std::ofstream file((this->getTarget() + "_shrubbery").c_str());
	if (!file.is_open())
		throw std::runtime_error("open error");
	file << "   ^  " << std::endl
		 << "  ^^^ " << std::endl
		 << " ~~|~~" << std::endl
		 << "   |  " << std::endl;
	file.close();
	return;
}
