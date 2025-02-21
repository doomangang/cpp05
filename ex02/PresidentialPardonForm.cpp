#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : _target("anywhere")
{
	std::cout << std::endl << GREY << "PresidentialPardonForm default constructor called\nTarget is" << RESET
	<< _target << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : _target(target)
{
	std::cout << std::endl << GREY << "PresidentialPardonForm constructor called\nTarget is " << RESET 
	<< _target << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other) {
	*this = other;
	std::cout << std::endl << GREY << "PresidentialPardonForm copy constructor called\n" << RESET;
}

PresidentialPardonForm::~PresidentialPardonForm() {
	std::cout << std::endl << GREY << "PresidentialPardonForm destructor called\n" << RESET;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other) {
	std::cout << std::endl << GREY << "PresidentialPardonForm assignment operator called\n" << RESET;
	if (this != &other) {
		
	}
	return *this;
}
