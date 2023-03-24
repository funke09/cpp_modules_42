/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcherrad <zcherrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 03:11:27 by zcherrad          #+#    #+#             */
/*   Updated: 2023/03/24 03:11:28 by zcherrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

Intern::Intern() {
}

Intern::Intern(const Intern& other) {
    (void)other;
}

Intern& Intern::operator=(const Intern& other) {
    (void)other;
    return *this;
}

Intern::~Intern() {
}

AForm* Intern::makeForm(const std::string& name, const std::string& target) const {

    std::string formNames[3] = {"presidential pardon", "robotomy request", "shrubbery creation"};

    for (int i = 0; i < 3; i++) {
        if (name == formNames[i]) {
            std::cout << "Intern creates " << name << std::endl;
            switch (i) {
                case 0:
                    return new PresidentialPardonForm(target);
                case 1:
                    return new RobotomyRequestForm(target);
                case 2:
                    return new ShrubberyCreationForm(target);
                default:
                    std::cout << "Intern can't create " << name << std::endl;
                    break;
            }
        }
    }
    return(nullptr);
}