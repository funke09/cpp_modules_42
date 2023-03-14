#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

int main() {
    // Create a bureaucrat with grade 50
    Bureaucrat bureaucrat("John Doe", 50);
    std::cout << bureaucrat << std::endl;

    // Try to create a bureaucrat with grade 0 (should throw GradeTooHighException)
    try {
        Bureaucrat invalid_bureaucrat("Invalid", 0);
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    // Try to create a bureaucrat with grade 151 (should throw GradeTooLowException)
    try {
        Bureaucrat invalid_bureaucrat("Invalid", 151);
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    // Increment the bureaucrat's grade to 51
    bureaucrat.incrementGrade();
    std::cout << bureaucrat << std::endl;

    // Decrement the bureaucrat's grade to 50
    bureaucrat.decrementGrade();
    std::cout << bureaucrat << std::endl;

    // Create a form with sign grade 25, execute grade 50, and name "Test Form"
    Form form("Test Form", 25, 50);
    std::cout << form << std::endl;

    // Try to create a form with sign grade 0 (should throw GradeTooHighException)
    try {
        Form invalid_form("Invalid Form", 0, 50);
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    // Try to create a form with sign grade 151 (should throw GradeTooLowException)
    try {
        Form invalid_form("Invalid Form", 151, 50);
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    // Try to create a form with execute grade 0 (should throw GradeTooHighException)
    try {
        Form invalid_form("Invalid Form", 25, 0);
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    // Try to create a form with execute grade 151 (should throw GradeTooLowException)
    try {
        Form invalid_form("Invalid Form", 25, 151);
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    // Try to sign the form with the bureaucrat (should throw GradeTooLowException)
    // try {
    //     bureaucrat.signForm(form);
    // } catch (std::exception &e) {
    //     std::cout << e.what() << std::endl;
    // }

    // // Increment the bureaucrat's grade to 26
    // bureaucrat.incrementGrade();

    // // Sign the form with the bureaucrat
    // bureaucrat.signForm(form);

    // // Print the form to confirm it is signed
    // std::cout << form << std::endl;

    // // Create a new bureaucrat with grade 10
    // Bureaucrat low_grade_bureaucrat("Jane Smith", 10);
    // std::cout << low_grade_bureaucrat << std::endl;

    // // Try to sign the form with the new bureaucrat (should throw GradeTooLowException)
    // try {
    //     low_grade_bureaucrat.signForm(form);
    // } catch (std::exception &e) {
    //     std::cout << e.what() << std::endl;
    // }

    // // Try to execute the form with the bureaucrat (should throw FormNotSignedException)
    // try {
    //     bureaucrat.executeForm(form);
    // } catch (std::exception &e) {
    //     std::cout << e.what() << std::endl;
    // }
    return 0;
}
   

