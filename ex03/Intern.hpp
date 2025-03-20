#ifndef INTERN_HPP
#define INTERN_HPP

#include <iostream>
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

/* Color Sets */
#define RESET   "\033[0m"
#define BLACK   "\033[30m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define WHITE   "\033[37m"
#define GREY    "\033[38;5;250m"

class Intern {
private:
	/* member attributes */
public:
	/* OCF */
	Intern();
	Intern(const Intern& other);
	~Intern();
	Intern& operator=(const Intern& other);

	/* getter & setter */

	/* additional methods */
	AForm*	makeForm(std::string formName, std::string formTarget);
	AForm*	makePresidentialPardonForm(std::string formName);
	AForm*	makeRobotomyRequestForm(std::string formName);
	AForm*	makeShrubberyCreationForm(std::string formName);

	/* exception classes */
	class FormNotExist : public std::exception {
		public:
			const char *what() const throw();
	};
};

/* operators */
#endif