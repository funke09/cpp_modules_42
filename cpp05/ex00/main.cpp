/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcherrad <zcherrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 03:10:06 by zcherrad          #+#    #+#             */
/*   Updated: 2023/03/24 03:10:08 by zcherrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <iostream>

int main() {
    try {
        Bureaucrat high_grade_bureaucrat("Alice", 1);
        std::cout << high_grade_bureaucrat << std::endl;

        high_grade_bureaucrat.decrementGrade();
        std::cout << high_grade_bureaucrat << std::endl;

        high_grade_bureaucrat.incrementGrade();
        std::cout << high_grade_bureaucrat << std::endl;

        Bureaucrat low_grade_bureaucrat("Bob", 150);
        std::cout << low_grade_bureaucrat << std::endl;

        low_grade_bureaucrat.incrementGrade();
    } catch (std::exception & e) {
        std::cerr << e.what() << std::endl;
    }
    return 0;
}
