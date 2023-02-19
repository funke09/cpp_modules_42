/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcherrad <zcherrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 22:11:23 by zcherrad          #+#    #+#             */
/*   Updated: 2023/02/19 22:11:24 by zcherrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"
#include "HumanA.hpp"
#include "HumanB.hpp"

int main(int ac, char **av) 
{
    (void)av;
    if(ac != 1) {
        std::cout << "Usage: ./a.out" << std::endl;
        return 1;
    }
    Weapon knife("knife");
    HumanA john("John", knife);
    john.attack();

    Weapon gun("gun");
    HumanB mike("Mike");
    mike.setWeapon(gun);
    mike.attack();

    HumanB lucy("Lucy");
    lucy.attack();

    return 0;
}

