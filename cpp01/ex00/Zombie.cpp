/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcherrad <zcherrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 22:10:45 by zcherrad          #+#    #+#             */
/*   Updated: 2023/02/20 18:41:27 by zcherrad         ###   ########.fr       */
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
        std::cout << "Heap Zombie is destroyed" << std::endl;
}

void Zombie::announce()
{
    std::cout <<  Name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void Zombie::setName(std::string name)
{
    Name  = name;
}
