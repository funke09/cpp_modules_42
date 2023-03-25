#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <string>

class ScalarConverter {
public:
    static char convertChar(const std::string& str);
    static int convertInt(const std::string& str);
    static float convertFloat(const std::string& str);
    static double convertDouble(const std::string& str);
};

#endif 
