#include <iostream>
#include <vector>
#include <list>
#include <stdexcept>
#include "easyfind.hpp"

int main() {
    std::vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    v.push_back(5);
    std::list<int> l;
    l.push_back(10);
    l.push_back(20);
    l.push_back(30);
    l.push_back(40);
    l.push_back(50);

    try {
        std::vector<int>::iterator it_v = easyfind(v, 3);
        std::cout << "Value found in vector at index " << std::distance(v.begin(), it_v) << std::endl;
    } catch (const std::exception& e) {
        std::cout << e.what() << std::endl;
    }

    try {
        std::list<int>::iterator it_l = easyfind(l, 40);
        std::cout << "Value found in list at index " << std::distance(l.begin(), it_l) << std::endl;
    } catch (const std::exception& e) {
        std::cout << e.what() << std::endl;
    }

    try {
        easyfind(v, 10);
    } catch (const std::exception& e) {
        std::cout << e.what() << std::endl;
    }

    return 0;
}

