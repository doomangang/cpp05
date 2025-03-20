// #include <stdio.h>

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

void leak(void) { system("leaks Bureaucrat"); }

int main(void) {
  // atexit(leak);
  AForm *rrf = 0;
  try {
    Bureaucrat test1("test", 3);
    Intern intern1;
    rrf = intern1.makeForm("Non-existent form", "Bender4");
    std::cout << *rrf << std::endl;
    test1.signForm(*rrf);
    test1.executeForm(*rrf);
  } catch (std::exception &e) {
    std::cout << e.what() << std::endl;
  }
  delete rrf;
  rrf = 0;
}
