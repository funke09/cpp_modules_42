/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serialize.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcherrad <zcherrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 22:17:51 by zcherrad          #+#    #+#             */
/*   Updated: 2023/04/02 22:17:52 by zcherrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZE_HPP
#define SERIALIZE_HPP
#include <string>
#include <sstream>
#include <limits>
#include <stdexcept>
#include <cmath>
#include <iomanip>
#include <iostream>
#include "Data.hpp"
class Serializer {
public:
    Serializer();
    Serializer(const Serializer&other);
    Serializer& operator=(const Serializer&rhs);
    ~Serializer();
    static uintptr_t serialize(Data* ptr);
    static Data* deserialize(uintptr_t raw);
};

#endif