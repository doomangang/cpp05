#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("Presidential", 25, 5), _target("Gildong")
{
	std::cout << std::endl << GREY << "PresidentialPardonForm default constructor called\nTarget is" << RESET
	<< _target << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("Presidential", 25, 5), _target(target)
{
	std::cout << std::endl << GREY << "Custom PresidentialPardonForm constructor called\nTarget is " << RESET 
	<< _target << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other) : AForm(other)
{
	*this = other;
	std::cout << std::endl << GREY << "PresidentialPardonForm copy constructor called\n" << RESET;
}

PresidentialPardonForm::~PresidentialPardonForm() {
	std::cout << std::endl << GREY << "PresidentialPardonForm destructor called\n" << RESET;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other) {
	std::cout << std::endl << GREY << "PresidentialPardonForm assignment operator called\n" << RESET;
	if (this != &other) {
		_target = other._target;
	}
	return *this;
}

void	PresidentialPardonForm::execAction() const {
	std::cout << MAGENTA << "Great ZAPHOD BEEBLEBROX has pardoned " << _target << RESET << std::endl;
}