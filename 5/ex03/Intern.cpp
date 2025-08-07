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

// Argument: Follows Open/Closed Principle, Factory Design Pattern, makeForm function is closed for modification, open for extension
AForm *createShrubbery(const std::string &target) { return new ShrubberyCreationForm(target); }
AForm *createRobotomy(const std::string &target) { return new RobotomyRequestForm(target); }
AForm *createPresidential(const std::string &target) { return new PresidentialPardonForm(target); }

AForm *Intern::makeForm(std::string formName, std::string formTarget)
{
	// Define a type for a function that creates an AForm
	typedef AForm *(*FormCreator)(const std::string &);

	// Pair form names with their creation functions
	struct FormType
	{
		std::string name;
		FormCreator creator;
	};

	FormType forms[] = {
		{"shrubbery creation", &createShrubbery},
		{"robotomy request", &createRobotomy},
		{"presidential pardon", &createPresidential}};

	for (int i = 0; i < 3; i++)
	{
		if (formName == forms[i].name)
		{
			std::cout << "Intern creates " << formName << std::endl;
			return forms[i].creator(formTarget);
		}
	}
	std::cout << "Intern does not know what form name to create" << std::endl;
	return (NULL);
}

// Argument: doesnt follow Open/Closed Principle, since adding new form requires modifying the main loop logic, meaning the function is "open" for modification
// AForm *Intern::makeForm(std::string formName, std::string formTarget)
// {
// 	std::string allFormNames[3] = {"robotomy request", "presidential pardon", "shrubbery creation"};

// 	for (int i = 0; i < 3; i++)
// 	{
// 		if (formName == allFormNames[i])
// 		{
// 			std::cout << "Intern creates " << formName << std::endl;
// 			switch (i)
// 			{
// 			case 0:
// 				return new RobotomyRequestForm(formTarget);
// 			case 1:
// 				return new PresidentialPardonForm(formTarget);
// 			case 2:
// 				return new ShrubberyCreationForm(formTarget);
// 			}
// 		}
// 	}
// 	std::cout << "Intern does not know what form name to create" << std::endl;
// 	return (NULL);
// }
