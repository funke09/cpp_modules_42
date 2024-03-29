/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcherrad <zcherrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 22:21:03 by zcherrad          #+#    #+#             */
/*   Updated: 2023/04/10 22:21:05 by zcherrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <iostream>
#include <stdexcept>

class Span {
public:
    Span();
    Span(const Span& other);
    Span& operator=(const Span& other);
    ~Span();
    Span(unsigned int n);

    void addNumber(int num);
    void addNumbers(const std::vector<int>& numbers); 

    int shortestSpan() const;
    int longestSpan() const;
private:
    std::vector<int> m_numbers;
    unsigned int m_size;
};

#endif
