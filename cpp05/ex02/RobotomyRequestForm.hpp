#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include <string>
#include <cstdlib>
#include <ctime>
#include "AForm.hpp"

class RobotomyRequestForm : public AForm {
public:
    RobotomyRequestForm(const std::string& target);
    RobotomyRequestForm(const RobotomyRequestForm& other);
    ~RobotomyRequestForm();
    RobotomyRequestForm& operator=(const RobotomyRequestForm& other);

    void execute(const Bureaucrat& executor) const;

private:
    RobotomyRequestForm();
    std::string _target;
};

#endif
