#include "Form.hpp"

const char *Form::GradeTooHighException::what() const throw()
{
	return "Grade is too high!";
}

const char *Form::GradeTooLowException::what() const throw()
{
	return "Grade is too low!";
}

const char *Form::NotEnoughGradeToSignException::what() const throw()
{
	return "Not enough grade to sign!";
}

const char *Form::AlreadySignedException::what() const throw()
{
	return "Form is already signed!";
}
Form::Form(void) : _name("default"), _issigned(false), _MinGradeToSign(Bureaucrat::LOWEST_GRADE), _MinGradeToExec(Bureaucrat::LOWEST_GRADE)
{
	return;
}

Form::Form(const std::string &name, int GradeOfSign, int GradeToExec) : _name(name), _issigned(false), _MinGradeToSign(GradeOfSign), _MinGradeToExec(GradeToExec)
{
	if (GradeOfSign < Bureaucrat::HIGHEST_GRADE || GradeToExec < Bureaucrat::HIGHEST_GRADE)
		throw Form::GradeTooHighException();
	if (GradeOfSign > Bureaucrat::LOWEST_GRADE || GradeToExec > Bureaucrat::LOWEST_GRADE)
		throw Form::GradeTooLowException();
	return;
}

Form::Form(const Form &src) : _name(src._name), _issigned(src._issigned), _MinGradeToSign(src._MinGradeToSign), _MinGradeToExec(src._MinGradeToExec)
{
	return;
}

Form &Form::operator=(const Form &src)
{
	if (this != &src)
	{
		// only _issigned is not const
		this->_issigned = src.getIsSigned();
	}
	return *(this);
}

Form::~Form(void)
{
	return;
}

const std::string &Form::getName(void) const
{
	return this->_name;
}

bool Form::getIsSigned(void) const
{
	return this->_issigned;
}

int Form::getMinGradeToSign(void) const
{
	return this->_MinGradeToSign;
}

int Form::getMinGradeToExec(void) const
{
	return this->_MinGradeToExec;
}

void Form::setIsSigned(bool issigned)
{
	this->_issigned = issigned;
}

// subject requires GradeTooLowException but not good
// 	this should throw Form::NotEnoughGradeToSignException();
void Form::beSigned(const Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() > this->getMinGradeToSign())
		throw Form::GradeTooLowException();
	if (this->getIsSigned())
		throw Form::AlreadySignedException();

	this->setIsSigned(true);
}

std::ostream &operator<<(std::ostream &o, const Form &form)
{
	o
		<< "╭─────────────────────╮" << std::endl
		<< "│Form name            │" << form.getName() << std::endl
		<< "│isSigned             │" << form.getIsSigned() << std::endl
		<< "│Min grade to sign    │" << form.getMinGradeToSign() << std::endl
		<< "│Min grade to execute │" << form.getMinGradeToExec() << std::endl
		<< "╰─────────────────────╯" << std::endl;

	return o;
}
