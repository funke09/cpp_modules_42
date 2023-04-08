#include "span.hpp"
#include <iostream>
#include <vector>
#include <algorithm>

// int main() {
//     Span sp(5);
//     sp.addNumber(6);
//     sp.addNumber(3);
//     sp.addNumber(17);
//     sp.addNumber(9);
//     sp.addNumber(11);
//     std::cout << sp.shortestSpan() << std::endl;
//     std::cout << sp.longestSpan() << std::endl;

//     std::vector<int> numbers;
//     numbers.push_back(15);
//     numbers.push_back(8);
//     numbers.push_back(23);
//     numbers.push_back(4);
//     numbers.push_back(7);
//     sp.addNumbers(numbers.begin(), numbers.end());
//     std::cout << sp.shortestSpan() << std::endl;
//     std::cout << sp.longestSpan() << std::endl;

//     return 0;
// }


int main()
{
    Span sp = Span(5);
    // sp.addNumber(6);
    // sp.addNumber(3);
    // sp.addNumber(17);
    // sp.addNumber(9);
    // sp.addNumber(11);
try {
    std::vector<int> numbers;
    numbers.push_back(15);
    numbers.push_back(8);
    numbers.push_back(23);
    numbers.push_back(4);
    numbers.push_back(7);
    numbers.push_back(70);
    numbers.push_back(78);
    sp.addNumbers(numbers);
} catch (const std::overflow_error& e) {
    std::cerr << "Error: " << e.what() << std::endl;
}
    std::cout << sp.shortestSpan() << std::endl;
    std::cout << sp.longestSpan() << std::endl;
    return 0;
}