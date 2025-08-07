/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwoon <cwoon@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 16:16:19 by cwoon             #+#    #+#             */
/*   Updated: 2025/08/07 17:21:51 by cwoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

void testShrubberyForm()
{
	Bureaucrat sam("sam", 1);
	Bureaucrat somedude("somedude", 150);
	ShrubberyCreationForm form("test");

	sam.executeForm(form);
	sam.signForm(form);
	somedude.executeForm(form);
	sam.executeForm(form);
}

void testRobotomyForm()
{
	Bureaucrat sam("sam", 1);
	Bureaucrat somedude("somedude", 150);
	RobotomyRequestForm form("test");

	sam.executeForm(form);
	sam.signForm(form);
	somedude.executeForm(form);
	sam.executeForm(form);
}

void testPresidentialForm()
{
	Bureaucrat sam("sam", 1);
	Bureaucrat somedude("somedude", 150);
	PresidentialPardonForm form("test");

	sam.executeForm(form);
	sam.signForm(form);
	somedude.executeForm(form);
	sam.executeForm(form);
}

int main()
{
	testShrubberyForm();
	testRobotomyForm();
	testPresidentialForm();
	return 0;
}
