#include <iostream>
#include <string>
#include "iter.hpp"

template <typename T>
void print(const T& value) {
    std::cout << value << " ";
}

template <typename T>
void square(T& value) {
    value *= value;
}

int main() {
    int int_array[] = {1, 2, 3, 4, 5};
    std::cout << "Original int array: ";
    iter(int_array, 5, print<int>);
    std::cout << std::endl;

    std::cout << "Squared int array: ";
    iter(int_array, 5, square<int>);
    iter(int_array, 5, print<int>);
    std::cout << std::endl;

    double double_array[] = {1.0, 2.0, 3.0, 4.0, 5.0};
    std::cout << "Original double array: ";
    iter(double_array, 5, print<double>);
    std::cout << std::endl;

    std::cout << "Squared double array: ";
    iter(double_array, 5, square<double>);
    iter(double_array, 5, print<double>);
    std::cout << std::endl;

    std::string string_array[] = {"one", "two", "three", "four", "five"};
    std::cout << "Original string array: ";
    iter(string_array, 5, print<std::string>);
    std::cout << std::endl;

    std::cout << "Uppercase string array: ";
    iter(string_array, 5, [](std::string& s){ 
        for (char& c : s) c = toupper(c); 
    });
    iter(string_array, 5, print<std::string>);
    std::cout << std::endl;

    return 0;
}
