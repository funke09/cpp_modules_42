#include "AForm.hpp"

AForm::AForm(const std::string& name, int sign_grade, int exec_grade) :
    name_(name),
    signed_(false),
    sign_grade_(sign_grade),
    exec_grade_(exec_grade)
{
    if (sign_grade_ < 1 || exec_grade_ < 1) {
        throw GradeTooHighException();
    }
    else if (sign_grade_ > 150 || exec_grade_ > 150) {
        throw GradeTooLowException();
    }
}

AForm::AForm(const AForm& other) :
    name_(other.name_),
    signed_(other.signed_),
    sign_grade_(other.sign_grade_),
    exec_grade_(other.exec_grade_)
{
}

AForm& AForm::operator=(const AForm& other) {
    if (this != &other) {
        signed_ = other.signed_;
    }
    return *this;
}

AForm::~AForm() {
}

const std::string& AForm::getName() const {
    return name_;
}

bool AForm::isSigned() const {
    return signed_;
}

int AForm::getSignGrade() const {
    return sign_grade_;
}

int AForm::getExecGrade() const {
    return exec_grade_;
}

void AForm::beSigned(const Bureaucrat& bureaucrat) {
    if (bureaucrat.getGrade() > sign_grade_) {
        throw GradeTooLowException();
    }
    signed_ = true;
}

const char* AForm::GradeTooHighException::what() const throw() {
    return "Grade too high";
}

const char* AForm::GradeTooLowException::what() const throw() {
    return "Grade too low";
}

const char* AForm::NotSignedException::what() const throw() {
    return "Form is not signed";
}

std::ostream& operator<<(std::ostream& os, const AForm& form) {
    os << form.getName() << ", form grade required to sign it: " << form.getSignGrade()
       << ", grade required to execute it: " << form.getExecGrade()
       << ", is " << (form.isSigned() ? "" : "not ") << "signed.";
    return os;
}
