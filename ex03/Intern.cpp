#include "Intern.hpp"

Intern::Intern() {
	std::cout << std::endl << GREY << "Intern default constructor called\n" << RESET;
}

Intern::Intern(const Intern& other) {
	*this = other;
	std::cout << std::endl << GREY << "Intern copy constructor called\n" << RESET;
}

Intern::~Intern() {
	std::cout << std::endl << GREY << "Intern destructor called\n" << RESET;
}

Intern& Intern::operator=(const Intern& other) {
	std::cout << std::endl << GREY << "Intern assignment operator called\n" << RESET;
	if (this != &other)
		return *this;
	return *this;
}

const char *Intern::FormNotExist::what() const throw () { 
	return ("Form you asked DOES NOT EXIST!");
}

AForm*	Intern::makeForm(std::string formName, std::string formTarget)
{
	std::string	formType[3] = {
		"Presidential Pardon",
		"Robotomy Resquest",
		"Shrubbery Creation"
	};

	AForm*	(Intern::*formFactories[3])(std::string) = {
		&Intern::makePresidentialPardonForm,
		&Intern::makeRobotomyRequestForm,
		&Intern::makeShrubberyCreationForm
	};

	for (int i = 0 ; i < 3 ; i++) {
		if (formName == formType[i]) {
			std::cout << GREEN << "Intern creates " << formType[i] << " form" << RESET << std::endl;
			AForm *form = (this->*formFactories[i])(formTarget);
			return form;
		}
	}
	throw FormNotExist();
}

AForm*	Intern::makePresidentialPardonForm(std::string target) { return new PresidentialPardonForm(target);}
AForm*	Intern::makeRobotomyRequestForm(std::string target)  { return new RobotomyRequestForm(target);}
AForm*	Intern::makeShrubberyCreationForm(std::string target)  { return new ShrubberyCreationForm(target);}
