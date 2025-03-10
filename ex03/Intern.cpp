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
	if (this != &other) {
		// assignment code here
	}
	return *this;
}