/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcherrad <zcherrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 22:17:23 by zcherrad          #+#    #+#             */
/*   Updated: 2023/04/02 22:17:25 by zcherrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <ctime>
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base* generate() {
    std::srand(std::time(0));
    int rand_num = std::rand() % 3;
    switch (rand_num) {
        case 0:
            return new A();
        case 1:
            return new B();
        default:
            return new C();
    }
}
