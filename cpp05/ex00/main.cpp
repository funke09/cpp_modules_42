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
