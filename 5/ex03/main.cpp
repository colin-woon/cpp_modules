/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwoon <cwoon@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 16:16:19 by cwoon             #+#    #+#             */
/*   Updated: 2025/08/06 21:20:44 by cwoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

void testShrubberyForm()
{
	Bureaucrat sam("sam", 1);
	Bureaucrat somedude("somedude", 150);
	ShrubberyCreationForm form("test");

	sam.executeForm(form);
	sam.signAForm(form);
	somedude.executeForm(form);
	sam.executeForm(form);
}

void testRobotomyForm()
{
	Bureaucrat sam("sam", 1);
	Bureaucrat somedude("somedude", 150);
	RobotomyRequestForm form("test");

	sam.executeForm(form);
	sam.signAForm(form);
	somedude.executeForm(form);
	sam.executeForm(form);
}

void testPresidentialForm()
{
	Bureaucrat sam("sam", 1);
	Bureaucrat somedude("somedude", 150);
	PresidentialPardonForm form("test");

	sam.executeForm(form);
	sam.signAForm(form);
	somedude.executeForm(form);
	sam.executeForm(form);
}

void testIntern()
{
	Intern sam;

	sam.makeForm("something", "somethign");
	AForm *shrubForm = sam.makeForm("shrubbery creation", "test1");
	AForm *presidentForm = sam.makeForm("presidential pardon", "test2");
	AForm *robotomyForm = sam.makeForm("robotomy request", "test3");

	std::cout << *shrubForm << std::endl
			  << *presidentForm << std::endl
			  << *robotomyForm << std::endl;

	delete shrubForm;
	delete presidentForm;
	delete robotomyForm;
}

int main()
{
	// testShrubberyForm();
	// testRobotomyForm();
	// testPresidentialForm();
	testIntern();
	return 0;
}
