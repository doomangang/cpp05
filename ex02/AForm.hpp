#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>

#include "Bureaucrat.hpp"

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

class Bureaucrat;

class AForm {
private:
	/* member attributes */
	const std::string	_name;
	bool				_isSigned;
	const int			_signGrade;
	const int			_execGrade;

public:
	/* OCF */
	AForm();
	AForm(std::string name, int sGrade, int eGrade);
	AForm(const AForm& other);
	~AForm();
	AForm& operator=(const AForm& other);

	/* getter & setter */
	std::string			getName() const;
	bool				getSigned() const;
	int					getSignGrade() const;
	int					getExecGrade() const;
	void				setSigned(Bureaucrat& bureau);

	/* exception classes */
	class GradeTooHighException : public std::exception {
		public:
			virtual const char *what() const throw();
	};

	class GradeTooLowException : public std::exception {
		public:
			virtual const char *what() const throw();
	};
};

/* operators */
std::ostream	&operator<<(std::ostream &os, const AForm& form);

#endif