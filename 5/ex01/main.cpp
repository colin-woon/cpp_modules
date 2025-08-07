/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwoon <cwoon@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 16:16:19 by cwoon             #+#    #+#             */
/*   Updated: 2025/08/07 17:16:55 by cwoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

void testConstructors()
{
	std::cout << "\n=== Testing Constructors ===\n";

	// Default constructor
	try
	{
		Form b1;
		std::cout << b1 << " (Default constructor OK)\n";
	}
	catch (std::exception &e)
	{
		std::cout << "Unexpected exception: " << e.what() << std::endl;
	}

	// Parameterized constructor - valid cases
	try
	{
		Form b2("A", 150, 150);
		std::cout << b2 << " (Parameterized constructor highest grade OK)\n";

		Form b3("B", 1, 1);
		std::cout << b3 << " (Parameterized constructor lowest grade OK)\n";
	}
	catch (std::exception &e)
	{
		std::cout << "Unexpected exception: " << e.what() << std::endl;
	}

	// Copy constructor
	try
	{
		Form original("Original", 42, 42);
		Form copy(original);
		std::cout << copy << " (Copy constructor OK)\n";
	}
	catch (std::exception &e)
	{
		std::cout << "Unexpected exception: " << e.what() << std::endl;
	}
}

void testGradeLimits()
{
	std::cout << "\n=== Testing Grade Limits ===\n";

	// Test too high grade
	try
	{
		Form b("TooHigh", 0, 0);
		std::cout << "Failed: Should have thrown GradeTooHighException\n";
	}
	catch (const Form::GradeTooHighException &e)
	{
		std::cout << "Caught expected exception: " << e.what() << std::endl;
	}

	// Test too low grade
	try
	{
		Form b("TooLow", 151, 151);
		std::cout << "Failed: Should have thrown GradeTooLowException\n";
	}
	catch (const Form::GradeTooLowException &e)
	{
		std::cout << "Caught expected exception: " << e.what() << std::endl;
	}
}

void testAssignmentOperator()
{
	std::cout << "\n=== Testing Assignment Operator ===\n";

	Form b1("First", 42, 42);
	Form b2("Second", 84, 84);

	std::cout << "Before assignment:\n";
	std::cout << "b1: " << b1 << std::endl;
	std::cout << "b2: " << b2 << std::endl;

	b2 = b1;

	std::cout << "After assignment:\n";
	std::cout << "b1: " << b1 << std::endl;
	std::cout << "b2: " << b2 << std::endl;
}

void testSignForm()
{
	Bureaucrat highBureau("Sam", 1);
	Bureaucrat lowBureau("Tom", 150);
	Form highForm("highForm", 1, 1);

	std::cout << highForm << std::endl;
	lowBureau.signForm(highForm);
	highBureau.signForm(highForm);
}

int main()
{
	// testConstructors();
	// testGradeLimits();
	// testAssignmentOperator();
	testSignForm();

	return 0;
}
