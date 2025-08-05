/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwoon <cwoon@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 16:16:21 by cwoon             #+#    #+#             */
/*   Updated: 2025/08/05 16:16:23 by cwoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("Default"), _grade(150) {}

Bureaucrat::Bureaucrat(const Bureaucrat &other) : _name(other.getName()), _grade(other.getGrade()) {}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other)
{
	if (this != &other)
	{
		this->_grade = other.getGrade();
	}
	return *this;
}

Bureaucrat::~Bureaucrat() {}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name), _grade(grade)
{
	try
	{
		if (grade < 1)
			throw GradeTooHighException();
		if (grade > 150)
			throw GradeTooLowException();
	}
	catch (const std::exception &e)
	{
		std::cerr << "Caught Exception: " << e.what() << std::endl;
	}
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return "Grade is too high!";
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return "Grade is too low!";
}

int Bureaucrat::getGrade() const
{
	return _grade;
}

void Bureaucrat::setGrade(int newGrade)
{
	try
	{
		if (newGrade < 1)
			throw GradeTooHighException();
		if (newGrade > 150)
			throw GradeTooLowException();
		_grade = newGrade;
	}
	catch (const std::exception &e)
	{
		std::cerr << "Caught exception:" << e.what() << std::endl;
	}
}

void Bureaucrat::incrementGrade()
{
	try
	{
		if (_grade <= 1)
			throw GradeTooHighException();
		_grade--;
	}
	catch (const std::exception &e)
	{
		std::cerr << "Caught exception: " << e.what() << std::endl;
	}
}

void Bureaucrat::decrementGrade()
{
	try
	{
		if (_grade >= 150)
			throw GradeTooLowException();
		_grade++;
	}
	catch (const std::exception &e)
	{
		std::cerr << "Caught exception: " << e.what() << std::endl;
	}
}

const std::string &Bureaucrat::getName() const
{
	return _name;
}

std::ostream &operator<<(std::ostream &out, Bureaucrat const &value)
{
	out << value.getName() << ", bureaucrat grade " << value.getGrade();
	return out;
}
