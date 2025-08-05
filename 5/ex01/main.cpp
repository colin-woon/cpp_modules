/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwoon <cwoon@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 16:16:19 by cwoon             #+#    #+#             */
/*   Updated: 2025/08/05 16:17:42 by cwoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <iostream>

void testConstructors()
{
	std::cout << "\n=== Testing Constructors ===\n";

	// Default constructor
	try
	{
		Bureaucrat b1;
		std::cout << b1 << " (Default constructor OK)\n";
	}
	catch (std::exception &e)
	{
		std::cout << "Unexpected exception: " << e.what() << std::endl;
	}

	// Parameterized constructor - valid cases
	try
	{
		Bureaucrat b2("Bob", 1);
		std::cout << b2 << " (Parameterized constructor highest grade OK)\n";

		Bureaucrat b3("Alice", 150);
		std::cout << b3 << " (Parameterized constructor lowest grade OK)\n";
	}
	catch (std::exception &e)
	{
		std::cout << "Unexpected exception: " << e.what() << std::endl;
	}

	// Copy constructor
	try
	{
		Bureaucrat original("Original", 42);
		Bureaucrat copy(original);
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
		Bureaucrat b("TooHigh", 0);
		std::cout << "Failed: Should have thrown GradeTooHighException\n";
	}
	catch (const Bureaucrat::GradeTooHighException &e)
	{
		std::cout << "Caught expected exception: " << e.what() << std::endl;
	}

	// Test too low grade
	try
	{
		Bureaucrat b("TooLow", 151);
		std::cout << "Failed: Should have thrown GradeTooLowException\n";
	}
	catch (const Bureaucrat::GradeTooLowException &e)
	{
		std::cout << "Caught expected exception: " << e.what() << std::endl;
	}
}

void testGradeModification()
{
	std::cout << "\n=== Testing Grade Modification ===\n";

	Bureaucrat b("Tester", 75);
	std::cout << "Initial: " << b << std::endl;

	// Test increment
	b.incrementGrade();
	std::cout << "After increment: " << b << std::endl;

	// Test decrement
	b.decrementGrade();
	std::cout << "After decrement: " << b << std::endl;

	// Test increment at maximum
	Bureaucrat topGrade("TopGrade", 1);
	std::cout << "\nTesting increment at top grade: " << topGrade << std::endl;
	topGrade.incrementGrade();

	// Test decrement at minimum
	Bureaucrat bottomGrade("BottomGrade", 150);
	std::cout << "\nTesting decrement at bottom grade: " << bottomGrade << std::endl;
	bottomGrade.decrementGrade();
}

void testAssignmentOperator()
{
	std::cout << "\n=== Testing Assignment Operator ===\n";

	Bureaucrat b1("First", 42);
	Bureaucrat b2("Second", 84);

	std::cout << "Before assignment:\n";
	std::cout << "b1: " << b1 << std::endl;
	std::cout << "b2: " << b2 << std::endl;

	b2 = b1;

	std::cout << "After assignment:\n";
	std::cout << "b1: " << b1 << std::endl;
	std::cout << "b2: " << b2 << std::endl;
}

int main()
{
	testConstructors();
	testGradeLimits();
	testGradeModification();
	testAssignmentOperator();

	return 0;
}
