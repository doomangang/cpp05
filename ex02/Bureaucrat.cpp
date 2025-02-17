#include "Bureaucrat.hpp"

/* exception */
const char *Bureaucrat::GradeTooHighException::what() const throw() {
	return ("Error: Grade is higher than 1!");
}

const char *Bureaucrat::GradeTooLowException::what() const throw() {
	return ("Error: Grade is lower than 150!");
}

Bureaucrat::Bureaucrat() : _name("default"), _grade(150)
{
	std::cout <<std::endl << GREY << "Bureaucrat default constructor called\n" << RESET << *this;
}

Bureaucrat::Bureaucrat(const std::string name, int grade) : _name(name)
{
	if (grade < 1)
		throw GradeTooHighException();
	if (grade > 150)
		throw GradeTooLowException();
	_grade = grade;
	std::cout <<std::endl  << GREY << "Custom bureaucrat constructor called\n" << RESET << *this;
}

Bureaucrat::Bureaucrat(const Bureaucrat& other) : _name(other._name), _grade(other._grade)
{
	std::cout <<std::endl  << GREY << "Bureaucrat copy constructor called\n" << RESET << *this;
}

Bureaucrat::~Bureaucrat() {
	std::cout << GREY << "Bureaucrat destructor called\n" << RESET;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other) {
	std::cout <<std::endl  << GREY << "Bureaucrat assignment operator called\n" << RESET;
	if (this != &other) {
		this->_grade = other._grade;
	}
	std::cout << *this;
	return *this;
}

std::string	Bureaucrat::getName() const { return _name; }

int	Bureaucrat::getGrade() const { return _grade; }

void	Bureaucrat::incrementGrade() {
	if (_grade - 1 < 1)
		throw GradeTooHighException();
	_grade = _grade - 1;
	std::cout << *this;
}

void	Bureaucrat::decrementGrade() {
	if (_grade + 1 > 150)
		throw GradeTooLowException();
	_grade = _grade + 1;
	std::cout << *this;
}

void	Bureaucrat::signForm(Form& form)
{
	try
	{
		form.setSigned(*this);
		std::cout  <<std::endl << GREEN << _name << " signed " << form.getName() << RESET << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << std::endl <<RED << _name << " couldn't sign " << form.getName() << " because " << e.what() << RESET << "\n";
	}
	
}

std::ostream	&operator<<(std::ostream &os, const Bureaucrat& bureau) {
	os << std::endl << GREEN << bureau.getName() << ", bureaucrat grade " << bureau.getGrade() << "." << RESET << std::endl;
	return os;
}
