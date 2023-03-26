#include "ScalarConverter.hpp"
#include <iostream>
#include <sstream>
#include <cmath>
#include <sstream>
#include <iostream>
#include <iomanip>

char ScalarConverter::convertChar(const std::string& str) {
    if (str.length() != 1) {
        std::cout << str.length() << std::endl;
        std::cerr << "Error: invalid char literal \"" << str << "\"\n";
        return '\0';
    }
    return str[0];
}

int ScalarConverter::convertInt(const std::string& str) {
    int result;
    std::istringstream iss(str);
    if (!(iss >> result)) {
        std::cerr << "Error: invalid int literal \"" << str << "\"\n";
        return 0;
    }
    return result;
}

float ScalarConverter::convertFloat(const std::string& str) {
    float result;
    std::istringstream iss(str);
    if (!(iss >> result)) {
        if (str == "-inff" || str == "+inff" || str == "nanf") {
            if (str == "-inff") result = -INFINITY;
            else if (str == "+inff") result = INFINITY;
            else if (str == "nanf") result = NAN;
        } else {
            std::cerr << "Error: invalid float literal \"" << str << "\"\n";
            result = 0.0f;
        }
    }
    std::ostringstream oss;
    oss << std::fixed << std::setprecision(2) << result;
    return "0." + oss.str();
}
double ScalarConverter::convertDouble(const std::string& str) {
    double result;
    std::istringstream iss(str);
    if (!(iss >> result)) {
        if (str == "-inf" || str == "+inf" || str == "nan") {
            if (str == "-inf") result = -INFINITY;
            else if (str == "+inf") result = INFINITY;
            else if (str == "nan") result = NAN;
        } else {
            std::cerr << "Error: invalid double literal \"" << str << "\"\n";
            result = 0.0;
        }
    }
    return result;
}
