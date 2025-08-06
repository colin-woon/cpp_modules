#include "Form.hpp"

Form::Form() : _name("Default Form"), _isSigned(false), _gradeToSign(150), _gradeToExecute(150) {}

Form::Form(const Form &other) : _name(other.getName()), _isSigned(other.getIsSigned()), _gradeToSign(other.getGradeToSign()), _gradeToExecute(other.getGradeToExecute()) {}

Form &Form::operator=(const Form &other)
{
	if (this != &other)
	{
		this->_isSigned = other.getIsSigned();
	}
	return *this;
}

Form::~Form() {}

Form::Form(std::string name, int gradeToSign, int gradeToExecute) : _name(name), _isSigned(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
	if (_gradeToSign > 150 || _gradeToExecute > 150)
		throw GradeTooLowException();
	if (_gradeToSign < 1 || _gradeToExecute < 1)
		throw GradeTooHighException();
}

const char *Form::GradeTooHighException::what() const throw()
{
	return "Form Grade is too high!";
}

const char *Form::GradeTooLowException::what() const throw()
{
	return "Grade too low to sign form!";
}

const std::string &Form::getName() const
{
	return _name;
}

bool Form::getIsSigned() const
{
	return _isSigned;
}

int Form::getGradeToSign() const
{
	return _gradeToSign;
}

int Form::getGradeToExecute() const
{
	return _gradeToExecute;
}

void Form::beSigned(const Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() <= this->getGradeToSign())
		this->_isSigned = true;
	else
		throw GradeTooLowException();
}

std::ostream &operator<<(std::ostream &out, Form const &value)
{
	out << std::boolalpha;
	out << value.getName() << ", Form sign status: " << value.getIsSigned() << std::endl
		<< "Grade to sign: " << value.getGradeToSign() << std::endl
		<< "Grade to execute: " << value.getGradeToExecute() << std::endl;
	return out;
}
