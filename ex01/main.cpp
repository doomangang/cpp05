#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
    try
    {
        Bureaucrat bob("Bob", 50);
        Form contract("Top Secret Contract", 40, 20);

        bob.signForm(contract);

        Bureaucrat alice("Alice", 30);
        alice.signForm(contract);

        std::cout << contract << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr  <<std::endl << RED << e.what() <<RESET << std::endl
		<< "-------------------------------" << std::endl;
    }

    return 0;
}