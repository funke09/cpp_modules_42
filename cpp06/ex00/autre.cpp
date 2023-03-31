#include <iostream>
#include <sstream>
#include <limits>
#include <sstream>
#include <iomanip>
#include <math.h> 
#include <limits>
#include <cmath>
#include <string>
#include <stdexcept>
#include <iostream>
#include <limits>

class ScalarConverter {
public:
    static char convertChar(const std::string& str) {
        if(str.length() == 1)
        {
            char result = str.c_str()[0];
            if(std::isdigit(result))
                return '\0';
            else
                return static_cast<char>(result);
        }
        return '\0';
    }

    static int convertInt(const std::string& str) {
        int result = std::atoi(str.c_str());
        if (result > INT_MAX || result < INT_MIN || !std::isdigit(str[0]))
            return -1;
        return static_cast<int>(result);
    }

    static float convertFloat(const std::string& str) {
        if(str == "0")
            return 0.f;
        float result = std::strtof(str.c_str(), nullptr);
        if(result > std::numeric_limits<float>::max() 
        || result < std::numeric_limits<float>::min())
        {
          std::cout << result << std::endl;
            return -1;
        }

         if(str == "nan" || str == "inf" || str == "-inf" || str == "+inf")
        {
          if(str == "nan")
            return 42;
          else if(str == "inf")
            return 1;
          else if(str == "-inf")
            return 2;
          else if(str == "+inf")
            return 3;
        }
        return static_cast<float>(result);
    }

    static double convertDouble(const std::string& str) {
        if(str == "0")
            return 0.0;
        double result = std::strtod(str.c_str(), nullptr);
        if(str == "nan" || str == "inf" || str == "-inf" || str == "+inf")
        {
          if(str == "nan")
            return 42;
          else if(str == "inf")
            return 1;
          else if(str == "-inf")
            return 2;
          else if(str == "+inf")
            return 3;
        }
        if(!std::isdigit(str[0]) || result >= std::numeric_limits<double>::max() 
        || result <= std::numeric_limits<double>::min())
            return -1;
        else 
          return static_cast<double>(result);
    }
};


// int main(int ac, char **av)
// {=.50/
//     if (ac != 2) {
//         std::cerr << "Usage: " << av[0] << " <literal>\n";
//         return 1;
//     }

//     std::string input(av[1]);

//     std::cout << "char: ";
//     try {
//         char c = ScalarConverter::convertChar(input);
//         if (std::isprint(c)) {
//             if (c == '0')
//                 std::cout << "Non displayable" << std::endl;
//             else
//                 std::cout << "'" << c << "'" << std::endl;
//         } else {
//             std::cout << "Non displayable" << std::endl;
//         }
//     } catch (std::exception &e) {
//         std::cout << "impossible" << std::endl;
//     }

//     std::cout << "int: ";
//     try {
//         int i = ScalarConverter::convertInt(input);
//         if (i != -1)
//             std::cout << i << std::endl;
//     } catch (std::exception &e) {
//         std::cout << "impossible" << std::endl;
//     }

//     std::cout << "float: ";
//     try {
//         float f = ScalarConverter::convertFloat(input);
//         char result = static_cast<char>(f);
//         if (result == '0')
//             std::cout << std::fixed << std::setprecision(1) << f << "f" << std::endl;
//         else
//             std::cout << f << "f" << std::endl;
//     } catch (std::exception &e) {
//         std::cout << "impossible" << std::endl;
//     }

//     std::cout << "double: ";
//     try {
//         double d = ScalarConverter::convertDouble(input);
//         char result = static_cast<char>(d);
//         if (result == '0')
//             std::cout << std::fixed << std::setprecision(1) << d << std::endl;
//         else
//             std::cout << d << std::endl;
//     } catch (std::exception &e) {
//         std::cout << "impossible" << std::endl;
//     }

//     return 0;
// }

#include <iostream>
#include <limits>
#include <sstream>
#include <string>

// #include "ScalarConverter.hpp"

int main(int argc, char* argv[]) {
  if (argc != 2) {
    std::cerr << "Usage: " << argv[0] << " <literal>" << std::endl;
    return 1;
  }

  std::string str(argv[1]);
  ScalarConverter converter;

  char c = converter.convertChar(str);
  int i = converter.convertInt(str);
  float f = converter.convertFloat(str);
  double d = converter.convertDouble(str);

  std::cout << "char: ";
  if (c == '\0' || c < 32 || c > 126) {
    std::cout << "Non displayable" << std::endl;
  } else {
    std::cout <<"'" << c << "'" << std::endl;
  }

  std::cout << "int: ";
  if (i == -1) {
    std::cout << "Impossible" << std::endl;
  } else {
    std::cout << i << std::endl;
  }

  std::cout << "float: ";
  // std::cout << f << std::endl;
  if (f == 1)
    std::cout << "inff" << std::endl;
  else if (f == 2)
    std::cout << "-inff" << std::endl;
  else if (f == 3)
    std::cout << "+inff" << std::endl;
  else if (f == 42)
    std::cout << "nanf" << std::endl;
   else if(converter.convertFloat(str) != -1) {
    std::cout << std::setprecision(1) << std::fixed << f << "f" << std::endl;
  }
  else {
    std::cout << "Impossible" << std::endl;
  }

  std::cout << "double: ";
  // if(d == 1)
  //   std::cout << "inf" << std::endl;
  // else if(d == 2)
  //   std::cout << "-inf" << std::endl;
  // else if(d == 3)
  //   std::cout << "+inf" << std::endl;
  // else if(d == 42)
  //   std::cout << "nan" << std::endl;
   if (isnan(d)) {
    std::cout << "nan" << std::endl;
  } else if (isinf(d)) {
    std::cout << ((d > 0) ? "inf" : "-inf") << std::endl;
  }
  else if(converter.convertDouble(str) != -1 && converter.convertDouble(str) != 42 && converter.convertDouble(str) != 1 
          && converter.convertDouble(str) != 2 && converter.convertDouble(str) != 3) {
    std::cout << std::setprecision(1) << std::fixed << d << std::endl;
  }
  else {
    std::cout << "Impossible" << std::endl;
  }

  return 0;
}
