#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
    try
    {
        Bureaucrat bob("Bob", 50);
        Form contract("Top Secret Contract", 40, 20);

        std::cout << contract << std::endl;
        bob.signForm(contract); // グレードが低いため署名できない

        Bureaucrat alice("Alice", 30);
        alice.signForm(contract); // 署名可能

        std::cout << contract << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }

    try
    {
        Bureaucrat alice("Alice", 150);
        std::cout << alice << std::endl;

        alice.decrementGrade();
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}