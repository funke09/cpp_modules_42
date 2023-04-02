/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcherrad <zcherrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 22:18:17 by zcherrad          #+#    #+#             */
/*   Updated: 2023/04/02 22:18:30 by zcherrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP
#include <string>
#include <sstream>
#include <limits>
#include <stdexcept>
#include <cmath>
#include <iomanip>
#include <iostream>


class ScalarConverter {
public: 
    ScalarConverter();
    ScalarConverter(const ScalarConverter&other);
    ScalarConverter& operator=(const ScalarConverter&rhs);
    ~ScalarConverter();

    static char toChar(const std::string& str);
    static int toInt(const std::string& str);
    static float toFloat(const std::string& str);
    static double toDouble(const std::string& str);
    static void convert(const std::string& str);
};

#endif