#include "RobotomyRequestAForm.hpp"

RobotomyRequestAForm::RobotomyRequestAForm() {}

RobotomyRequestAForm::RobotomyRequestAForm(const RobotomyRequestAForm &other)
{
	this->value = other.value;
}

RobotomyRequestAForm &RobotomyRequestAForm::operator=(const RobotomyRequestAForm &other)
{
	if (this != &other)
	{
		this->value = other.value;
	}
	return *this;
}

RobotomyRequestAForm::~RobotomyRequestAForm() {}
