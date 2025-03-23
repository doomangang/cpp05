#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("Robotomy", 72, 45), _target("Default")
{
	std::cout << std::endl << GREY << "RobotomyRequestForm default constructor called\n" << RESET;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("Robotomy", 72, 45), _target(target)
{
	std::cout << std::endl << GREY << "Custom RobotomyRequestForm constructor called\n" << RESET;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other) :AForm(other)
{
	*this = other;
	std::cout << std::endl << GREY << "RobotomyRequestForm copy constructor called\n" << RESET;
}

RobotomyRequestForm::~RobotomyRequestForm() {
	std::cout << std::endl << GREY << "RobotomyRequestForm destructor called\n" << RESET;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other) {
	std::cout << std::endl << GREY << "RobotomyRequestForm assignment operator called\n" << RESET;
	if (this != &other) {
		_target = other._target;
	}
	return *this;
}

void	RobotomyRequestForm::execAction() const {
	std::cout << BLUE << "Drrrriiiilllll" << std::endl;
	srand(time(NULL));
	int	randNum = rand() % 2;
	if (randNum == 1)
		std::cout << GREEN << this->_target << " has been ROBOTOMIZED" << RESET << std::endl;
	else
		std::cout << RED << this->_target << " FAILED to be ROBOTOMIZED" << RESET << std::endl;
}
