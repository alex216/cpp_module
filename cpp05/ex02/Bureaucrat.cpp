#include "Bureaucrat.hpp"

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return "Grade is too high";
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return "Grade is too low";
}

Bureaucrat::Bureaucrat(void) :
	_name("Default"),
	_grade(Bureaucrat::LOWEST_GRADE)
{
	return;
}

Bureaucrat::Bureaucrat(const std::string &name, int grade) :
	_name(name),
	_grade(grade)
{
	if (grade < Bureaucrat::HIGHEST_GRADE)
		throw Bureaucrat::GradeTooHighException();
	if (grade > Bureaucrat::LOWEST_GRADE)
		throw Bureaucrat::GradeTooLowException();
	return;
}

Bureaucrat::Bureaucrat(const Bureaucrat &src) :
	_name(src.getName()),
	_grade(src.getGrade())
{
	return;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &src)
{
	if (this != &src)
	{
		// _name is const, so it cannot be assigned to
		this->_grade = src.getGrade();
	}
	return *(this);
}

Bureaucrat::~Bureaucrat(void)
{
	return;
}

const std::string &Bureaucrat::getName(void) const
{
	return this->_name;
}

int Bureaucrat::getGrade(void) const
{
	return this->_grade;
}

void Bureaucrat::incrementGrade(void)
{
	if (this->getGrade() == Bureaucrat::HIGHEST_GRADE)
		throw Bureaucrat::GradeTooHighException();
	this->_grade--;
}

void Bureaucrat::decrementGrade(void)
{
	if (this->getGrade() == Bureaucrat::LOWEST_GRADE)
		throw Bureaucrat::GradeTooLowException();
	this->_grade++;
}

void Bureaucrat::signForm(AForm &aform) const
{
	try
	{
		aform.beSigned(*this);
		std::cout << this->getName() << "\tsigned " << aform.getName() << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << this->getName() << "\tcouldn't sign " << aform.getName() << " because " << e.what() << std::endl;
	}
}

void Bureaucrat::executeForm(AForm const & aform) const
{
	try
	{
		aform.execute(*this);
		std::cout << this->getName() << "\texecuted " << aform.getName() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << this->getName() << "\tcouldn't execute " << aform.getName() << " because " << e.what() << std::endl;
	}
}

std::ostream &operator<<(std::ostream &o, const Bureaucrat &src)
{
	o << src.getName() << "\tbureaucrat grade\t" << src.getGrade();
	return o;
}
