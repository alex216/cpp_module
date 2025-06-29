#include "AForm.hpp"

const char *AForm::GradeTooHighException::what() const throw()
{
	return "Grade is too high!";
}

const char *AForm::GradeTooLowException::what() const throw()
{
	return "Grade is too low!";
}
const char *AForm::NotEnoughGradeToSignException::what() const throw()
{
	return "Not enough grade to sign!";
}

const char *AForm::AlreadySignedException::what() const throw()
{
	return "Form is already signed!";
}

const char *AForm::NotEnoughGradeToExecException::what() const throw()
{
	return "Not enough grade to execute!";
}

const char *AForm::NotSignedException::what() const throw()
{
	return "Form is not signed!";
}

AForm::AForm(void) : _name("default"), _issigned(false),  _MinGradeToSign(Bureaucrat::LOWEST_GRADE), _MinGradeToExec(Bureaucrat::LOWEST_GRADE)
{
	return;
}

AForm::AForm(const std::string &name, int GradeOfSign, int GradeToExec) : _name(name), _issigned(false), _MinGradeToSign(GradeOfSign), _MinGradeToExec(GradeToExec)
{
	if (GradeOfSign < Bureaucrat::HIGHEST_GRADE || GradeToExec < Bureaucrat::HIGHEST_GRADE)
		throw AForm::GradeTooHighException();
	if (GradeOfSign > Bureaucrat::LOWEST_GRADE || GradeToExec > Bureaucrat::LOWEST_GRADE)
		throw AForm::GradeTooLowException();
	return;
}

AForm::AForm(const AForm &src) : _name(src._name), _issigned(src._issigned), _MinGradeToSign(src._MinGradeToSign), _MinGradeToExec(src._MinGradeToExec)
{
	return;
}

AForm &AForm::operator=(const AForm &src)
{
	if (this != &src)
	{
		// only _issigned is not const
		this->_issigned = src.getIsSigned();
	}
	return *(this);
}

AForm::~AForm(void)
{
	return;
}

const std::string &AForm::getName(void) const
{
	return this->_name;
}

bool AForm::getIsSigned(void) const
{
	return this->_issigned;
}

int AForm::getMinGradeToSign(void) const
{
	return this->_MinGradeToSign;

}

int AForm::getMinGradeToExec(void) const
{
	return this->_MinGradeToExec;
}

void AForm::setIsSigned(bool issigned)
{
	this->_issigned = issigned;
}

void	AForm::beSigned(const Bureaucrat &executor)
{
	if (executor.getGrade() > this->getMinGradeToSign())
		throw AForm::NotEnoughGradeToSignException();
	if (this->getIsSigned())
		throw AForm::AlreadySignedException();

	this->setIsSigned(true);
}

std::ostream &operator<<(std::ostream &o, const AForm &form)
{
	o \
		<< "╭─────────────────────╮" << std::endl \
		<< "│AForm name           │" << form.getName() << std::endl \
		<< "│isSigned             │" << form.getIsSigned() << std::endl \
		<< "│Min grade to sign    │" << form.getMinGradeToSign() << std::endl \
		<< "│Min grade to execute │" << form.getMinGradeToExec() << std::endl \
		<< "╰─────────────────────╯" << std::endl \
	;
	
	return o;
}
