#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("Shrubbery", 145, 137), _target("Anywhere")
{
	std::cout << std::endl << GREY << "ShrubberyCreationForm default constructor called\n" << RESET;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("Shrubbery", 145, 137), _target(target)
{
	std::cout << std::endl << GREY << "Custom ShrubberyCreationForm constructor called\n" << RESET;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other)  : AForm(other)
{
	*this = other;
	std::cout << std::endl << GREY << "ShrubberyCreationForm copy constructor called\n" << RESET;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
	std::cout << std::endl << GREY << "ShrubberyCreationForm destructor called\n" << RESET;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other) {
	std::cout << std::endl << GREY << "ShrubberyCreationForm assignment operator called\n" << RESET;
	if (this != &other) {
		_target = other._target;
	}
	return *this;
}

std::string	ShrubberyCreationForm::getFilename() { return _target + "_shrubbery"; }

void	ShrubberyCreationForm::execAction() const {
	std::string filename = this->_target + "_shrubbery";
	std::ofstream	file(filename.c_str());
	if (file.is_open())
	{
		file << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⢀⣀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀" << std::endl;
		file << "⠀⠀⠀⠀⢀⣀⠄⠠⠐⠐⠈⠀⠁⠒⠋⠁⠁⠁⠁⠁⠈⠈⠈⠀⢁⣁⡩⠇⠀⠀⠀⠀⠀⠀⠀⠀" << std::endl;
		file << "⠀⠀⢀⣀⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠉⠁⠁⠂⠄⡀⡀⠀⠀⠀⠀⠀⠀" << std::endl;
		file << "⢐⠋⠁⠀⠉⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠁⠑⢤⠀⠀⠀" << std::endl;
		file << "⠸⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠒⠚⠄⡀⠀" << std::endl;
		file << "⢸⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⢣" << std::endl;
		file << "⠀⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸" << std::endl;
		file << "⠀⠈⢦⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠤⣤⠤⠼" << std::endl;
		file << "⢰⠊⠁⠀⠀⠀⠀⠀⡠⡻⣁⣁⣀⣀⠤⠤⠤⠒⠒⠒⠒⠒⠒⠒⠒⠒⢲⢀⠀⠀⠀⠀⠀⠀⠃⡀" << std::endl;
		file << "⠀⣇⠀⠀⢀⡀⡤⠊⠀⠇⠀⠀⠀⠀⢀⣤⡄⠀⠀⠀⠀⣤⡄⠀⠀⠀⢸⠀⠣⡀⠀⠀⠀⠀⠀⠡" << std::endl;
		file << "⠀⠈⠉⠉⠁⠀⠀⠀⢠⠁⠀⠀⠀⢠⢻⡿⡟⠀⠀⠀⢸⣿⣿⠀⠀⠀⢸⠀⠀⠣⠄⠤⠤⠄⠂⠚" << std::endl;
		file << "⠀⠀⠀⠀⠀⠀⠀⠀⡸⠀⠀⠀⠀⠈⠉⠉⢁⢠⠀⠀⠑⠚⠋⠀⠀⠀⢸⠀⠀⠀⠀⠀⠀⠀⠀⠀" << std::endl;
		file << "⠀⠀⠀⠀⠀⠀⠀⢀⠆⠀⠀⠀⠀⠀⠀⠀⠀⠙⠷⠦⠤⠶⠀⠀⠀⠀⢸⠀⠀⠀⠀⠀⠀⠀⠀⠀" << std::endl;
		file << "⠀⠀⠀⠀⠀⠀⠀⠘⠒⠂⠒⠒⠂⠒⠤⠤⠤⢄⣀⣀⡀⠀⠀⠀⠀⠀⠘⡄⠀⠀⠀⠀⠀⠀⠀⠀" << std::endl;
		file << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠉⠉⠒⠒⠲⠤⠇⠀⠀⠀⠀⠀⠀⠀⠀" << std::endl;
		file.close();
		std::cout << GREEN << "shrubbery has successfully planted on " << _target << RESET << std::endl;
	}
	else {
		std::cerr << RED << "Error : cannot be opened\n" << RESET;
	}
}
