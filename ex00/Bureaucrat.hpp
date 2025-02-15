#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define GREY 	"\033[38;5;250m"

class Bureaucrat {
private:
	/* member attributes */
	const std::string	_name;
	int					_grade; // 1~150

public:
	/* OCF */
	Bureaucrat();
	Bureaucrat(const std::string name, int grade);
	Bureaucrat(const Bureaucrat& other);
	~Bureaucrat();
	Bureaucrat& operator=(const Bureaucrat& other);

	/* getter */
	std::string			getName() const;
	int					getGrade() const;
	/* additional methods */
	void				incrementGrade();
	void				decrementGrade();

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

/* << operator */
std::ostream	&operator<<(std::ostream &os, const Bureaucrat& bureau);

#endif