#include <iostream>
#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"

PresidentialPardonForm::PresidentialPardonForm(const std::string &target)
: AForm("PresidentialPardonForm", 25, 5), _target(target) {}

PresidentialPardonForm::~PresidentialPardonForm() {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &src)
: AForm(src), _target(src._target) {}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &rhs) {
    if (this != &rhs) {
        AForm::operator=(rhs);
        this->_target = rhs._target;
    }
    return *this;
}

void PresidentialPardonForm::execute(const Bureaucrat &executor) const {
    AForm::execute(executor);
    std::cout << _target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}
