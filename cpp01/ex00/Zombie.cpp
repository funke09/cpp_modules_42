/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcherrad <zcherrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 22:10:45 by zcherrad          #+#    #+#             */
/*   Updated: 2023/02/23 03:03:10 by zcherrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie()
{
    std::cout  << "Zombie created" << std::endl;
}

Zombie::~Zombie()
{
    if(Name != "")
        std::cout << Name << " is destroyed" << std::endl;
    else
        std::cout << "unkown Zombie is destroyed" << std::endl;
}

void Zombie::announce()
{
    if(Name != "")
        std::cout <<  Name << ": BraiiiiiiinnnzzzZ..." << std::endl;
    else
        std::cout << "unkown Zombie: BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie::Zombie(std::string name) : Name(name) {
    if(Name != "")
        std::cout << name << " created" << std::endl;
    else
        std::cout << "unkown Zombie created" << std::endl;
}
