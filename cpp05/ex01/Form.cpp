/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcherrad <zcherrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 03:10:18 by zcherrad          #+#    #+#             */
/*   Updated: 2023/03/24 03:10:22 by zcherrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form() : _name(""), _isSigned(false), _signGrade(150), _execGrade(150) {}

Form::Form(std::string const &name, int const signGrade, int const execGrade)
    : _name(name), _isSigned(false), _signGrade(signGrade), _execGrade(execGrade) {
    if (signGrade < 1 || execGrade < 1)
        throw Form::GradeTooHighException();
    else if (signGrade > 150 || execGrade > 150)
        throw Form::GradeTooLowException();
}

Form::Form(Form const &src)
    : _name(src._name), _isSigned(src._isSigned),
      _signGrade(src._signGrade), _execGrade(src._execGrade) {}

Form::~Form() {}

Form &Form::operator=(Form const &rhs) {
    if (this != &rhs) {
        this->_isSigned = rhs._isSigned;
    }
    return *this;
}

std::string const &Form::getName() const { return this->_name; }

int Form::getSignGrade() const { return this->_signGrade; }

int Form::getExecGrade() const { return this->_execGrade; }

bool Form::getIsSigned() const { return this->_isSigned; }

void Form::beSigned(Bureaucrat const &bureaucrat) {
    if (bureaucrat.getGrade() <= this->_signGrade)
        this->_isSigned = true;
    else
        throw Form::GradeTooLowException();
}

const char *Form::GradeTooHighException::what() const throw() {
    return "grade is too high";
}

const char *Form::GradeTooLowException::what() const throw() {
    return "grade is too low";
}

const char *Form::FormNotSignedException::what() const throw() {
    return "form is not signed";
}

std::ostream &operator<<(std::ostream &os, Form const &form) {
    os << "Form: " << form.getName() << ", "
       << "Grade required to sign: " << form.getSignGrade() << ", "
       << "Grade required to execute: " << form.getExecGrade() << ", "
       << "Is signed: " << (form.getIsSigned() ? "yes" : "no") << std::endl;
    return os;
}
