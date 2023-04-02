/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serialize.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcherrad <zcherrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 22:17:54 by zcherrad          #+#    #+#             */
/*   Updated: 2023/04/02 22:17:55 by zcherrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdint>
#include "Serialize.hpp"
#include "Data.hpp"



uintptr_t Serializer::serialize(Data* ptr)
    {
        return reinterpret_cast<uintptr_t>(ptr);
    }
Data* Serializer::deserialize(uintptr_t raw)
    {
        return reinterpret_cast<Data*>(raw);
    }

Serializer::Serializer(){}

Serializer::Serializer(const Serializer&other){
    *this = other;
}

Serializer &Serializer::operator=(const Serializer&rhs){
    if(this != &rhs)
    {
        *this = rhs;
    }
    return *this;
}

Serializer::~Serializer(){}

