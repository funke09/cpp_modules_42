#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include <string>
#include <fstream>
#include "AForm.hpp"

class ShrubberyCreationForm : public AForm {
public:
    ShrubberyCreationForm(const std::string& target);
    ShrubberyCreationForm(const ShrubberyCreationForm& other);
    ~ShrubberyCreationForm();
    ShrubberyCreationForm& operator=(const ShrubberyCreationForm& other);

    void execute(const Bureaucrat& executor) const;

private:
    ShrubberyCreationForm();
    std::string _target;
};

#endif
