#include "AForm.hpp"

const char *AForm::GradeTooHighException::what() const throw() {
	return ("Grade is TOO HIGH!");
}

const char *AForm::GradeTooLowException::what() const throw() {
	return ("Grade is TOO LOW to sign!");
}

const char *AForm::FormNotSignedException::what() const throw() {
	return ("Form is NOT SIGNED yet!");
}

AForm::AForm() : _name("default"), _isSigned(false), _signGrade(150), _execGrade(150)
{
	std::cout <<std::endl  << GREY << "AForm default constructor called\n" << RESET << *this;
}

AForm::AForm(const std::string name, int signGrade, int execGrade) : _name(name), _signGrade(signGrade), _execGrade(execGrade)
{
	if (signGrade < 1 || execGrade < 1)
		throw GradeTooHighException();
	if (signGrade > 150 || execGrade > 150)
		throw GradeTooLowException();
	_isSigned = false;
	std::cout <<std::endl  << GREY << "Custom AForm constructor called\n" << RESET << *this;
}

AForm::AForm(const AForm& other) : _name(other._name), _signGrade(other._signGrade), _execGrade(other._execGrade)
{
	*this = other;
	std::cout << std::endl  << GREY << "AForm copy constructor called\n" << RESET << *this;
}

AForm::~AForm() {
	std::cout << GREY << "AForm destructor called\n" << RESET;
}

AForm& AForm::operator=(const AForm& other) {
	std::cout <<std::endl  << GREY << "AForm assignment operator called\n" << RESET;
	if (this != &other) {
		_isSigned = other._isSigned;
	}
	std::cout << *this;
	return *this;
}

std::string	AForm::getName() const { return _name; }
bool	AForm::getSigned() const { return _isSigned; }
int	AForm::getSignGrade() const { return _signGrade; }
int	AForm::getExecGrade() const { return _execGrade; }

void	AForm::beSigned(Bureaucrat& bureau) {
	if (bureau.getGrade() > _signGrade)
		throw GradeTooLowException();
	_isSigned = true;
}

void	AForm::execute(Bureaucrat const& executor) const
{
	if (!this->getSigned())
		throw FormNotSignedException();
	if (executor.getGrade() > this->getExecGrade())
		throw GradeTooLowException();
	execAction();
}

std::ostream	&operator<<(std::ostream &os, const AForm& aform) {
	os << std::endl << GREEN << aform.getName() << CYAN << " info :" << RESET << std::endl 
		<< "AForm signed: " << GREEN << (aform.getSigned() ? "yes" : "no") << "," << RESET << std::endl 
		<< "AForm sign grade: " << GREEN << aform.getSignGrade() << "," << RESET << std::endl 
		<< "AForm execution grade: " << GREEN << aform.getExecGrade() << RESET << std::endl;

	return os;
}