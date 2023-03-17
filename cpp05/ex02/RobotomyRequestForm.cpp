#include <iostream>
#include <cstdlib>
#include <ctime>
#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"

RobotomyRequestForm::RobotomyRequestForm(const std::string &target)
: AForm("RobotomyRequestForm", 72, 45), _target(target) {
    std::srand(std::time(nullptr));
}

RobotomyRequestForm::~RobotomyRequestForm() {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &src)
: AForm(src), _target(src._target) {}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &rhs) {
    if (this != &rhs) {
        AForm::operator=(rhs);
        _target = rhs._target;
    }
    return *this;
}

void RobotomyRequestForm::execute(const Bureaucrat &executor) const {
    AForm::execute(executor);
    std::cout << "Drilling noises..." << std::endl;
    if (std::rand() % 2) {
        std::cout << _target << " has been robotomized successfully!" << std::endl;
    } else {
        std::cout << "Robotomy failed for " << _target << "." << std::endl;
    }
}
