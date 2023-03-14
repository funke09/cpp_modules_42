#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>
#include <iostream>
#include <stdexcept>

class Bureaucrat {
public:
    class GradeTooHighException : public std::exception {
    public:
        virtual const char *what() const throw() {
            return "Grade is too high.";
        }
    };

    class GradeTooLowException : public std::exception {
    public:
        virtual const char *what() const throw() {
            return "Grade is too low.";
        }
    };

    Bureaucrat(const std::string &name, int grade);
    Bureaucrat(const Bureaucrat &src);
    virtual ~Bureaucrat();

    Bureaucrat &operator=(const Bureaucrat &rhs);

    const std::string &getName() const;
    int getGrade() const;
    void incrementGrade();
    void decrementGrade();

private:
    const std::string _name;
    int _grade;
};

std::ostream &operator<<(std::ostream &out, const Bureaucrat &b);

#endif
