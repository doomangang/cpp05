
#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"

int main()
{
	try
	{
		std::cout << "\n\033[1;32m--------tree---------------\033[0m\n";
		Bureaucrat	bureau("bureau_tree", 3);
		ShrubberyCreationForm form_shrub("house");
		bureau.signForm(form_shrub);
		bureau.executeForm(form_shrub);

		std::cout << GREEN << "let's check if shrubbery REALLY has been successfully planted" << RESET << std::endl;
		std::string	filename = form_shrub.getFilename();
		std::ifstream	file(filename);
		if (!file) {
			std::cerr <<RED << "failed to open " << filename << RESET <<std::endl;
		}

		std::string line;
		while (std::getline(file, line)) {
			std::cout << line << std::endl;
		}
		file.close();

		std::cout << "\n\033[1;32m---------president--------------\033[0m\n";
		Bureaucrat	bureau2("bureau_president", 2);
		PresidentialPardonForm form_president("john");
		bureau2.signForm(form_president);
		form_president.execute(bureau2);

		std::cout << "\n\033[1;32m---------robo--------------\033[0m\n";
		Bureaucrat	bureau3("bureau_robo", 2);
		RobotomyRequestForm form_robo("alien");
		bureau3.signForm(form_robo);
		bureau3.executeForm(form_robo);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}