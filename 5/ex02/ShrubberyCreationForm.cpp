#include "ShrubberyCreationAForm.hpp"

ShrubberyCreationAForm::ShrubberyCreationAForm() {}

ShrubberyCreationAForm::ShrubberyCreationAForm(const ShrubberyCreationAForm &other)
{
	this->value = other.value;
}

ShrubberyCreationAForm &ShrubberyCreationAForm::operator=(const ShrubberyCreationAForm &other)
{
	if (this != &other)
	{
		this->value = other.value;
	}
	return *this;
}

ShrubberyCreationAForm::~ShrubberyCreationAForm() {}
