#include <iostream>
#include <string>
#include <sstream>
#include <limits>
#include <stdexcept>
#include <cmath>
#include <iomanip>


class ScalarConverter {
public:
    static char toChar(const std::string& str) {
        if(isdigit(str[0]) || (str[0] == '-' && isdigit(str[1])) || (str[0] == '+' && isdigit(str[1])))
        {
            int ss = std::atoi(str.c_str());
            if (ss >= 32 && ss <= 126)
                return static_cast<char>(ss);
            else if(ss < 32 || ss > 126)
                throw std::invalid_argument("Non displayable");
        }
        else 
        {
            if(str.length() == 1)
            {
                char c;
                std::stringstream ss(str);
                ss >> c;
                if (ss.fail() || ss.eof())
                    throw std::invalid_argument("Invalid char literalyy");
                return static_cast<char>(c);
            }
            else
                throw std::invalid_argument("Impossible");
        }
        return '\0';
        
    }

    static int toInt(const std::string& str) {
        if(isdigit(str[0]) || (str[0] == '-' && isdigit(str[1])) || (str[0] == '+' && isdigit(str[1])))
        {
            int i = std::atoi(str.c_str());
            return static_cast<int>(i);
        }
        return -1;
    }

    static float toFloat(const std::string& str) {
        if(isdigit(str[0]) || (str[0] == '-' && isdigit(str[1])) || (str[0] == '+' && isdigit(str[1])))
        {
            float f = std::atof(str.c_str());
            return static_cast<float>(f);
        }
        if (str == "+inff" || str == "inf" || str == "+inf") {
            return std::numeric_limits<float>::infinity();
        } else if (str == "-inff" || str == "-inf") {
            return -std::numeric_limits<float>::infinity();
        } else if (str == "nanf" || str == "nan") {
            return std::numeric_limits<float>::quiet_NaN();
        }
        return -1;
    }

    static double toDouble(const std::string& str) {
        if(isdigit(str[0]) || (str[0] == '-' && isdigit(str[1])) || (str[0] == '+' && isdigit(str[1])))
        {
            double d = std::strtod(str.c_str(), NULL);
            return static_cast<double>(d);
        }
        if (str == "+inf" || str == "inf" || str == "+inf") {
            return std::numeric_limits<double>::infinity();
        } else if (str == "-inf") {
            return -std::numeric_limits<double>::infinity();
        } else if (str == "nan") {
            return std::numeric_limits<double>::quiet_NaN();
        } 
        return -1;
    }

    static void convert(const std::string& str) {
        try {
            std::cout << "char: " << toChar(str) << std::endl;
        } catch (const std::invalid_argument& e) {
            std::cout << e.what() << std::endl;
        }

        try {
            std::cout << "int: ";
            if(toInt(str) != -1)
                std::cout << toInt(str) << std::endl;
            else 
                std::cout << "Impossible" << std::endl;
        } catch (const std::invalid_argument& e) {
            std::cout << e.what() << std::endl;
        }

        try {
            std::cout << "float: ";
            if(toFloat(str) != -1)
                std::cout << std::setprecision(1) << std::fixed 
                << toFloat(str) << "f" << std::endl;
            else
                std::cout << "Impossible" << std::endl;
        } catch (const std::invalid_argument& e) {
            std::cout << e.what() << std::endl;
        }

        try {
            std::cout << "double: ";
            if(toDouble(str) != -1)
                std::cout << std::setprecision(1) << std::fixed 
                << toDouble(str) << std::endl;
            else 
                std::cout << "Impossible" << std::endl;
        } catch (const std::invalid_argument& e) {
            std::cout << e.what() << std::endl;
        }
    }
};



int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cout << "Usage: " << argv[0] << " <literal>" << std::endl;
        return 1;
    }

    std::string input(argv[1]);
    ScalarConverter::convert(input);
    return 0;
}
