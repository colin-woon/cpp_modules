#include "Intern.hpp"

Intern::Intern() {}

Intern::Intern(const Intern &other)
{
	(void)other;
}

Intern &Intern::operator=(const Intern &other)
{
	(void)other;
	return *this;
}

Intern::~Intern() {}

AForm *Intern::makeForm(std::string formName, std::string formTarget)
{
	std::string allFormNames[3] = {"robotomy request", "presidential pardon", "shrubbery creation"};

	for (int i = 0; i < 3; i++)
	{
		if (formName == allFormNames[i])
		{
			std::cout << "Intern creates " << formName << std::endl;
			switch (i)
			{
			case 0:
				return new RobotomyRequestForm(formTarget);
			case 1:
				return new PresidentialPardonForm(formTarget);
			case 2:
				return new ShrubberyCreationForm(formTarget);
			}
		}
	}
	std::cout << "Intern does not know what form name to create" << std::endl;
	return (NULL);
}
