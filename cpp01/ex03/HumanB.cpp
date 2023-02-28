/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcherrad <zcherrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 22:11:17 by zcherrad          #+#    #+#             */
/*   Updated: 2023/02/19 22:11:19 by zcherrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"
#include <iostream>

HumanB::HumanB(std::string name) : _name(name), _weapon(NULL) {}

void HumanB::setWeapon(Weapon& weapon) {
    _weapon = &weapon;
}

void HumanB::attack() const {
    std::cout << _name << " attacks with ";
    if (_weapon)
        std::cout << "their " << _weapon->getType();
    else
        std::cout << "no weapon";
    std::cout << std::endl;
}
