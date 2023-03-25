// #include "ScalarConverter.hpp"
// #include <iostream>

// int main() {
//     char c = ScalarConverter::convertChar("a");
//     int i = ScalarConverter::convertInt("-42");
//     float f = ScalarConverter::convertFloat("4.2f");
//     double d = ScalarConverter::convertDouble("-inf");

//     std::cout << c << ", " << i << ", " << f << ", " << d << "\n";

//     return 0;
// }




#include "ScalarConverter.hpp"
#include <iostream>
#include <limits>
#include <cmath>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <literal>\n";
        return 1;
    }

    ScalarConverter converter;
    std::string input(argv[1]);

    std::cout << "char: ";
    try {
        char c = converter.convertChar(input);
        if (std::isprint(c)) {
            std::cout << "'" << c << "'\n";
        } else {
            std::cout << "Non displayable\n";
        }
    } catch (std::exception &e) {
        std::cout << "impossible\n";
    }

    std::cout << "int: ";
    try {
        int i = converter.convertInt(input);
        std::cout << i << "\n";
    } catch (std::exception &e) {
        std::cout << "impossible\n";
    }

    std::cout << "float: ";
    try {
        float f = converter.convertFloat(input);
        if (f == std::numeric_limits<float>::infinity()) {
            std::cout << "+inff\n";
        } else if (f == -std::numeric_limits<float>::infinity()) {
            std::cout << "-inff\n";
        } else if (std::isnan(f)) {
            std::cout << "nanf\n";
        } else {
            std::cout << f << "f\n";
        }
    } catch (std::exception &e) {
        std::cout << "impossible\n";
    }

    std::cout << "double: ";
    try {
        double d = converter.convertDouble(input);
        if (d == std::numeric_limits<double>::infinity()) {
            std::cout << "+inf\n";
        } else if (d == -std::numeric_limits<double>::infinity()) {
            std::cout << "-inf\n";
        } else if (std::isnan(d)) {
            std::cout << "nan\n";
        } else {
            std::cout << d << "\n";
        }
    } catch (std::exception &e) {
        std::cout << "impossible\n";
    }

    return 0;
}
