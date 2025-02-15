#include "Form.hpp"

const char *Form::GradeTooHighException::what() const throw() {
	return ("Grade is TOO HIGH!");
}

const char *Form::GradeTooLowException::what() const throw() {
	return ("Grade is TOO LOW to sign!");
}

Form::Form() : _name("default"), _isSigned(false), _signGrade(150), _execGrade(150)
{
	std::cout << GREY << "Form default constructor called\n" << RESET << *this;
}

Form::Form(const std::string name, int signGrade, int execGrade) : _name(name), _signGrade(signGrade), _execGrade(execGrade)
{
	if (signGrade < 1 || execGrade < 1)
		throw GradeTooHighException();
	if (signGrade > 150 || execGrade > 150)
		throw GradeTooLowException();
	_isSigned = false;
	std::cout << GREY << "Custom form constructor called\n" << RESET << *this;
}

Form::Form(const Form& other) : _name(other._name), _signGrade(other._signGrade), _execGrade(other._execGrade)
{
	*this = other;
	std::cout << GREY << "Form copy constructor called\n" << RESET << *this;
}

Form::~Form() {
	std::cout << GREY << "\nForm destructor called\n" << RESET;
}

Form& Form::operator=(const Form& other) {
	std::cout << GREY << "Form assignment operator called\n" << RESET;
	if (this != &other) {
		_isSigned = other._isSigned;
	}
	std::cout << *this;
	return *this;
}

std::string	Form::getName() const { return _name; }
bool	Form::getSigned() const { return _isSigned; }
int	Form::getSignGrade() const { return _signGrade; }
int	Form::getExecGrade() const { return _execGrade; }

void	Form::beSigned(Bureaucrat& bureau) {
	if (bureau.getGrade() > _signGrade)
		throw GradeTooLowException();
	_isSigned = true;
}

std::ostream	&operator<<(std::ostream &os, const Form& form) {
	os << GREEN << form.getName() << CYAN << " info :" << RESET << std::endl 
		<< "form signed: " << GREEN << (form.getSigned() ? "yes" : "no") << "," << RESET << std::endl 
		<< "form sign grade: " << GREEN << form.getSignGrade() << "," << RESET << std::endl 
		<< "form execution grade: " << GREEN << form.getSigned() << RESET << std::endl 
		<< std::endl;
	return os;
}