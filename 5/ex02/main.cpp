/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwoon <cwoon@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 16:16:19 by cwoon             #+#    #+#             */
/*   Updated: 2025/08/06 19:25:38 by cwoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"

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

int main()
{
	// testShrubberyForm();
	testRobotomyForm();
	return 0;
}
