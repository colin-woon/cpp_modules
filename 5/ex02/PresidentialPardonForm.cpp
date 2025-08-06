#include "PresidentialPardonAForm.hpp"

PresidentialPardonAForm::PresidentialPardonAForm() {}

PresidentialPardonAForm::PresidentialPardonAForm(const PresidentialPardonAForm &other)
{
	this->value = other.value;
}

PresidentialPardonAForm &PresidentialPardonAForm::operator=(const PresidentialPardonAForm &other)
{
	if (this != &other)
	{
		this->value = other.value;
	}
	return *this;
}

PresidentialPardonAForm::~PresidentialPardonAForm() {}
