/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcherrad <zcherrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 21:54:52 by zcherrad          #+#    #+#             */
/*   Updated: 2023/04/05 21:54:54 by zcherrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Array.hpp"

int main() {
    // Create an empty array
    Array<int> arr1;
    std::cout << "arr1 size: " << arr1.size() << std::endl;

    // Create an array with 5 elements initialized to 0
    Array<int> arr2(5);
    std::cout << "arr2 size: " << arr2.size() << std::endl;

    // Fill the array with values and print them
    for (int i = 0; i < arr2.size(); i++) {
        arr2[i] = i * 10;
        std::cout << "arr2[" << i << "]: " << arr2[i] << std::endl;
    }

    // Create a copy of arr2 and modify the copy
    Array<int> arr3 = arr2;
    arr3[2] = 99;

    // Print the original array to ensure it was not modified
    std::cout << "arr2 after copy: ";
    for (int i = 0; i < arr2.size(); i++) {
        std::cout << arr2[i] << " ";
    }
    std::cout << std::endl;

    // Print the modified copy
    std::cout << "arr3 after copy: ";
    for (int i = 0; i < arr3.size(); i++) {
        std::cout << arr3[i] << " ";
    }
    std::cout << std::endl;

    // Try to access an out-of-bounds index
    try {
        std::cout << "arr2[10]: " << arr2[10] << std::endl;
    } catch (std::exception& e) {
        std::cout << "Exception: out-of-bounds!"<< std::endl;
    }

    return 0;
}
