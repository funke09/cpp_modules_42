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
            if(c == '0')
                std::cout << "Non displayable" << std::endl;
            else
            std::cout << "'" << c << "'" << std::endl;
        // } else {
        //     std::cout << "Non displayable" << std::endl;
        }
    } catch (std::exception &e) {
        std::cout << "impossible" << std::endl;
    }

    std::cout << "int: ";
    try {
        int i = converter.convertInt(input);
        if(i != -1)
            std::cout << i << std::endl;
    } catch (std::exception &e) {
        std::cout << "impossible" << std::endl;
    }

    std::cout << "float: ";
    try {
        float f = converter.convertFloat(input);
        if(input == "0")
            std::cout << "0.0f" << std::endl;
        if (f == std::numeric_limits<float>::infinity()) {
            std::cout << "+inff\n";
        } else if (f == -std::numeric_limits<float>::infinity()) {
            std::cout << "-inff\n";
        } else if (std::isnan(f)) {
            std::cout << "nanf\n";
        } 
        else
         std::cout << std::fixed << f << std::endl;
    } catch (std::exception &e) {
        std::cout << "impossible\n";
    }

    std::cout << "double: ";
    try {
        double d = converter.convertDouble(input);
        if(input == "0")
            std::cout << "0.0" << std::endl;
        if (d == std::numeric_limits<double>::infinity()) {
            std::cout << "+inf\n";
        } else if (d == -std::numeric_limits<double>::infinity()) {
            std::cout << "-inf\n";
        } else if (std::isnan(d)) {
            std::cout << "nan\n";
        }
        else
            std::cout << d << std::endl;
    } catch (std::exception &e) {
        std::cout << "impossible\n";
    }

    return 0;
}
