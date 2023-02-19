#include <iostream>

int main(int ac, char **av)
{
    (void)av;
    if(ac != 1)
    {
        std::cout << "Error: No arguments needed" << std::endl;
        return 1;
    }
    std::string str = "HI THIS IS BRAIN";
    std::string *strPTR = &str;
    std::string &strREF = str;

    std::cout << "Memory address of string variable: " << &str << std::endl;
    std::cout << "Memory address held by stringPTR: " << strPTR << std::endl;
    std::cout << "Memory address held by stringREF: " << &strREF << std::endl;

    std::cout << "Value of the string variable: " << str << std::endl;
    std::cout << "Value pointed to by stringPTR: " << *strPTR << std::endl;
    std::cout << "Value pointed to by stringREF: " << strREF << std::endl;
}