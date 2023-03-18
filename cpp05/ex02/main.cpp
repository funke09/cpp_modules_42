#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main() {
    // Create a bureaucrat
    Bureaucrat bureaucrat("Bob", 1);

    // Create forms
    ShrubberyCreationForm shrubberyForm("garden");
    RobotomyRequestForm robotomyForm("Rob");
    PresidentialPardonForm pardonForm("John");

    // Sign forms
    try {
        shrubberyForm.beSigned(bureaucrat);
        robotomyForm.beSigned(bureaucrat);
        pardonForm.beSigned(bureaucrat);
    }
    catch (std::exception& e) {
        std::cerr << e.what() << std::endl;
        return 1;
    }

    // Execute forms
    shrubberyForm.execute(bureaucrat);
    robotomyForm.execute(bureaucrat);
    pardonForm.execute(bureaucrat);

    // Attempt to execute the same forms again
    shrubberyForm.execute(bureaucrat);
    robotomyForm.execute(bureaucrat);
    pardonForm.execute(bureaucrat);

    // Create a new bureaucrat
    Bureaucrat bureaucrat2("Bill", 150);

    // Try to sign forms with the new bureaucrat
    try {
        shrubberyForm.beSigned(bureaucrat2);
        robotomyForm.beSigned(bureaucrat2);
        pardonForm.beSigned(bureaucrat2);
    }
    catch (std::exception& e) {
        std::cerr << e.what() << std::endl;
        return 1;
    }

    // Try to execute forms with the new bureaucrat
    shrubberyForm.execute(bureaucrat2);
    robotomyForm.execute(bureaucrat2);
    pardonForm.execute(bureaucrat2);

    return 0;
}


