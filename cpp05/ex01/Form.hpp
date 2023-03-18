#ifndef FORM_HPP
#define FORM_HPP

#include <string>
#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form {
public:
    Form();
    Form(std::string const &name, int const signGrade, int const execGrade);
    Form(Form const &src);
    ~Form();

    Form &operator=(Form const &rhs);

    std::string const &getName() const;
    int getSignGrade() const;
    int getExecGrade() const;
    bool getIsSigned() const;
    void beSigned(Bureaucrat const &bureaucrat);

    class GradeTooHighException : public std::exception {
    public:
        virtual const char *what() const throw();
    };
    class GradeTooLowException : public std::exception {
    public:
        virtual const char *what() const throw();
    };
    class FormNotSignedException : public std::exception {
    public:
        virtual const char *what() const throw();
    };

private:
    std::string const _name;
    bool _isSigned;
    int const _signGrade;
    int const _execGrade;
};

std::ostream &operator<<(std::ostream &os, Form const &form);

#endif

