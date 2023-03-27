// #include <iostream>
// class chi_haja
// {
//     private:
//     const static int i = 100;
//     public:
//         static int func(int x,int y)
//         {
//             return x+y;
//         }
//         static int gettest()
//         {
//             return i;
//         }
// };

// int main()
// {
//     int a = chi_haja::gettest();

//     std::cout << a << std::endl;
//     return 0;
// }

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
#include <iostream>
#include <limits>
#include <sstream>
#include <string>

// class ScalarConverter {
// public:
//     static float convertFloat(const std::string& str);
// };

// float ScalarConverter::convertFloat(const std::string& str) {

//     if(str == "0")
//         return 0.0f;
//     float result;
//     std::istringstream iss(str);
//     if (!(iss >> result)) {
//         if (str == "-inff" || str == "+inff" || str == "nanf") {
//             if (str == "-inff") result = -INFINITY;
//             else if (str == "+inff") result = INFINITY;
//             else if (str == "nanf") result = NAN;
//         } else {
//             std::cerr << "Error: invalid float literal \"" << str << "\"\n";
//             result = 0.0f;
//         }
//     }
//     return result;
// }

// int main() {
//     std::string input1 = "3.14";
//     std::string input2 = "0";
//     std::string input3 = "abc";

//     float result1 = ScalarConverter::convertFloat(input1);
//     float result2 = ScalarConverter::convertFloat(input2);
//     float result3 = ScalarConverter::convertFloat(input3);

//     std::cout << result1 << std::endl;  // Output: 3.14
//     std::cout << result2 << std::endl;  // Output: 0
//     // Output error message for input3: "Error: invalid float literal "abc""
//     std::cout << result3 << std::endl;  // Output: 0

//     return 0;
// }


#include <iostream>
#include <sstream>
#include <limits>
#include <cmath>

float convertFloat(const std::string& str) {
    float result = 0.0f;
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
    return result;
}

int main() {
    float result1 = convertFloat("3.14");
    std::cout << std::fixed << result1 << std::endl;  // Output: 3.140000

    float result2 = convertFloat("0");
    std::cout << std::fixed << result2 << std::endl;  // Output: 0.000000

    float result3 = convertFloat("-inff");
    std::cout << std::fixed << result3 << std::endl;  // Output: -inf

    float result4 = convertFloat("nanf");
    std::cout << std::fixed << result4 << std::endl;  // Output: nan

    return 0;
}
