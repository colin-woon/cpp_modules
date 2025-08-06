#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("Default RobotomyRequestForm", 72, 45) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other) : AForm(other) {}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &other)
{
	if (this != &other)
	{
		AForm::operator=(other);
	}
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm() {}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm(target, 72, 45) {}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
	if (!this->getIsSigned())
		throw AForm::UnsignedFormException();
	if (executor.getGrade() > this->getGradeToExecute())
		throw AForm::GradeTooLowException();

	// Time(0) gives the current time in seconds
	// Seeds it into the random number generator so everytime different result
	// else the random sequence will always be the same
	std::srand(std::time(0));

	std::cout << "BZZZZZZZTTTTTT... drilling noises..." << std::endl;

	if (std::rand() % 2 == 0)
		std::cout << this->getName() << " has been robotomized successfully and cured from being restarted!" << std::endl;
	else
		std::cout << "Robotomy failed." << std::endl;
}
