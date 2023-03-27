#include "ScalarConverter.hpp"
#include <iostream>
#include <sstream>
#include <cmath>
#include <sstream>
#include <iostream>
#include <iomanip>

#include <sstream>
#include <iostream>
#include <iomanip>
#include <string>
#include <stdexcept>

float ostringstreamToFloat(std::ostringstream& oss) {
    std::string str = oss.str();
    std::istringstream iss(str);
    float result;

    if (!(iss >> result)) {
        throw std::runtime_error("Failed to parse float from string: " + str);
    }

    // std::cout << result << std::endl;
    return result;
}


char ScalarConverter::convertChar(const std::string& str) {
    if (str.length() != 1) {
        std::cerr << "Error: invalid char literal \"" << str << "\"" << std::endl;
        return '\0';
    }
    return str[0];
}

int ScalarConverter::convertInt(const std::string& str) {
    int result;
    std::istringstream iss(str);
    if (!(iss >> result)) {
        std::cerr << "Error: invalid int literal \"" << str << "\"" << std::endl;
        return -1;
    }
    return result;
}


float ScalarConverter::convertFloat(const std::string& str) {

    float result = 0.0f;
    std::istringstream iss(str);
    if (!(iss >> result)) {
        if (str == "-inff" || str == "+inff" || str == "nanf") {
            if (str == "-inff") result = -INFINITY;
            else if (str == "+inff") result = INFINITY;
            else if (str == "nanf") result = NAN;
        } else {
            std::cerr << "Error: invalid float literal \"" << str << "\"" << std::endl;
            result = 0.0f;
        }
    }
    return result;
}
double ScalarConverter::convertDouble(const std::string& str) {
    double result = 0.0;
    std::istringstream iss(str);
    if (!(iss >> result)) {
        if (str == "-inf" || str == "+inf" || str == "nan") {
            if (str == "-inf") result = -INFINITY;
            else if (str == "+inf") result = INFINITY;
            else if (str == "nan") result = NAN;
        } else {
            std::cerr << "Error: invalid double literal \"" << str << std::endl;
            result = 0.0;
        }
    }
    return result;
}
