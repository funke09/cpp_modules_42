/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcherrad <zcherrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 21:54:42 by zcherrad          #+#    #+#             */
/*   Updated: 2023/04/05 21:54:44 by zcherrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <iomanip>
#include "iter.hpp"


void convertToUpperCase(std::string& s) {
    for (size_t i = 0; i < s.length(); i++) {
        s[i] = toupper(s[i]);
    }
}


template <typename T>
void print(const T& value) {
    if (typeid(T) == typeid(float) || typeid(T) == typeid(double)) {
        std::cout.precision(1);
        std::cout.setf(std::ios::fixed);
        if(typeid(T) == typeid(float))
            std::cout << std::setprecision(1) << value << "f ";
        else if(typeid(T) == typeid(double))
            std::cout << std::setprecision(1) << value << " ";
    }
    else
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

    float float_array[] = {1.0f, 2.0f, 3.0f, 4.0f, 5.0f};
    std::cout << "Original float array: ";
    iter(float_array, 5, print<float>);
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
    iter(string_array, 5, convertToUpperCase);
    iter(string_array, 5, print<std::string>);
    std::cout << std::endl;

    return 0;
}
