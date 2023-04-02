/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   identify.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcherrad <zcherrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 22:17:21 by zcherrad          #+#    #+#             */
/*   Updated: 2023/04/02 22:17:22 by zcherrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

void identify(Base* p) {
    if (dynamic_cast<A*>(p) != NULL) {
        std::cout << "A" << std::endl;
    } else if (dynamic_cast<B*>(p) != NULL) {
        std::cout << "B" << std::endl;
    } else if (dynamic_cast<C*>(p) != NULL) {
        std::cout << "C" << std::endl;
    }
}

void identify(Base& p) {
    if (dynamic_cast<A*>(&p) != nullptr) {
        std::cout << "A" << std::endl;
    } else if (dynamic_cast<B*>(&p) != nullptr) {
        std::cout << "B" << std::endl;
    } else if (dynamic_cast<C*>(&p) != nullptr) {
        std::cout << "C" << std::endl;
    }
}
