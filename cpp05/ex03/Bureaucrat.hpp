#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>
#include <stdexcept>
#include <iostream>
#include "AForm.hpp"

class AForm;
class Bureaucrat {
public:
    Bureaucrat(std::string const& name, int grade);
    Bureaucrat(Bureaucrat const& other);
    Bureaucrat& operator=(Bureaucrat const& other);
    virtual ~Bureaucrat();

    std::string const& getName() const;
    int getGrade() const;

    void incrementGrade();
    void decrementGrade();
    void executeForm(AForm const& form);

    class GradeTooHighException : public std::exception {
    public:
        virtual const char* what() const throw();
    };
    class GradeTooLowException : public std::exception {
    public:
        virtual const char* what() const throw();
    };

private:
    std::string _name;
    int _grade;
};

std::ostream& operator<<(std::ostream& os, Bureaucrat const& bureaucrat);

#endif
