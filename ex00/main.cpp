#include "Bureaucrat.hpp"

int main()
{
    try
    {
        Bureaucrat bob("Bob", 2);

        std::cout << "\nAfter increment: ";
        bob.incrementGrade();
        bob.incrementGrade();
		std::cout << "\nerror thrown must be catched, this messaged should be ignored\n";
    }
    catch (const std::exception &e)
    {
        std::cerr << RED << std:: endl << e.what() << RESET << std::endl;
    }

    try
    {
		std::cout << std::endl;
        Bureaucrat alice("Alice", 150);
		std::cout << "\nthis message should be printed, and then destructor will be called next\n";
        alice.decrementGrade();
    }
    catch (const std::exception &e)
    {
        std::cerr << RED << std:: endl << e.what() << RESET << std::endl;
    }
    return 0;
}