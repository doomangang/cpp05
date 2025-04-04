#include <sstream>
#include "Intern.hpp"
#include "Bureaucrat.hpp"
#include "AForm.hpp"

int main() {
	Intern intern;
	Bureaucrat bureaucrat("John", 1);
	std::stringstream	ss;

	std::string formNames[4] = {
		"Presidential Pardon",
		"Robotomy Resquest",
		"Shrubbery Creation",
		"Invalid Form"
	};

	AForm *form = 0;
	for (int i = 0; i < 4; i++) {
		try {
			ss.str(std::string());
			ss << "Target" << i + 1;
			std::cout << BLUE << "\n[Requesting form: " << formNames[i] << "]" << RESET << std::endl;
			form = intern.makeForm(formNames[i], ss.str());
			std::cout << *form << std::endl;
			bureaucrat.signForm(*form);
			bureaucrat.executeForm(*form);
		}
		catch (const std::exception &e) {
			std::cerr << RED << "Error: " << e.what() << RESET << std::endl;
		}
		delete form;
		form = 0;
	}
	return 0;
}
