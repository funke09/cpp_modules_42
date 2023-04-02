/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcherrad <zcherrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 22:18:02 by zcherrad          #+#    #+#             */
/*   Updated: 2023/04/02 22:18:03 by zcherrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"
#include "Serialize.hpp"
#include <iostream>

int main() {
    Data data;
    data.number = 42;
    data.name = "Test";

    uintptr_t ptrValue = Serializer::serialize(&data);
    Data* deserialized = Serializer::deserialize(ptrValue);

    if (deserialized == &data) {
        std::cout << "Pointer deserialization succeeded!" << std::endl;
        std::cout << "Name: " << deserialized->name << std::endl;
        std::cout << "Number: " << deserialized->number << std::endl;
        std::cout << "Address deserialized: " << deserialized << std::endl;
        std::cout << "Address data: " << &data << std::endl;

        std::cout << "ptrValue ptr: "<<ptrValue << std::endl;
        std::cout << "ptrValue cast data: "<<reinterpret_cast<uintptr_t>(&data) << std::endl;

    } else {
        std::cout << "Pointer deserialization failed!" << std::endl;
    }
    
    return 0;
}

// int main(){
// 	Data data;
// 	data.name = "the name";

// 	std::cout << "first one " <<  data.name << std::endl;
	
// 	uintptr_t raw = Serializer::serialize(&data);

// 	Data	*data2 = Serializer::deserialize(raw);

// 	std::cout << "second one " << data2->name << std::endl;
// 	return 0;
// }
