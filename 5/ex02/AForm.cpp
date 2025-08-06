#include "AForm.hpp"

AForm::AForm() : _name("Default AForm"), _isSigned(false), _gradeToSign(150), _gradeToExecute(150) {}

AForm::AForm(const AForm &other) : _name(other.getName()), _isSigned(other.getIsSigned()), _gradeToSign(other.getGradeToSign()), _gradeToExecute(other.getGradeToExecute()) {}

AForm &AForm::operator=(const AForm &other)
{
	if (this != &other)
	{
		this->_isSigned = other.getIsSigned();
	}
	return *this;
}

AForm::~AForm() {}

AForm::AForm(std::string name, int gradeToSign, int gradeToExecute) : _name(name), _isSigned(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
	if (_gradeToSign > 150 || _gradeToExecute > 150)
		throw GradeTooLowException();
	if (_gradeToSign < 1 || _gradeToExecute < 1)
		throw GradeTooHighException();
}

const char *AForm::GradeTooHighException::what() const throw()
{
	return "AForm Grade is too high!";
}

const char *AForm::GradeTooLowException::what() const throw()
{
	return "Grade too low to sign AForm!";
}

const std::string &AForm::getName() const
{
	return _name;
}

bool AForm::getIsSigned() const
{
	return _isSigned;
}

int AForm::getGradeToSign() const
{
	return _gradeToSign;
}

int AForm::getGradeToExecute() const
{
	return _gradeToExecute;
}

void AForm::beSigned(const Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() <= this->getGradeToSign())
		this->_isSigned = true;
	else
		throw GradeTooLowException();
}

std::ostream &operator<<(std::ostream &out, AForm const &value)
{
	out << std::boolalpha;
	out << value.getName() << ", Form sign status: " << value.getIsSigned() << std::endl
		<< "Grade to sign: " << value.getGradeToSign() << std::endl
		<< "Grade to execute: " << value.getGradeToExecute() << std::endl;
	return out;
}
