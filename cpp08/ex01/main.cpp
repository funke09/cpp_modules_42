/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcherrad <zcherrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 22:20:52 by zcherrad          #+#    #+#             */
/*   Updated: 2023/04/10 22:20:54 by zcherrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "span.hpp"
#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    Span sp ;
    try{
        sp.addNumber(6);
        sp.addNumber(3);

    }catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
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

    std::cout << sp.shortestSpan() << std::endl;
    std::cout << sp.longestSpan() << std::endl;
} catch (const std::overflow_error& e) {
    std::cerr << "Error: " << e.what() << std::endl;
}

    return 0;
}