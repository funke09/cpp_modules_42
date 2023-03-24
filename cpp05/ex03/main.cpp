/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcherrad <zcherrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 03:11:33 by zcherrad          #+#    #+#             */
/*   Updated: 2023/03/24 03:11:34 by zcherrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main() {
    try {
        
        Intern intern;
        Bureaucrat employee("11", 1);
        AForm *form = intern.makeForm("robotomy request", "someone");
        if (form)
        {
            form->execute(employee);
            delete form;
        }
    }
        catch (std::exception& e){
            std::cout << "Error : " << e.what() << std::endl;
        }
    return 0;
}


