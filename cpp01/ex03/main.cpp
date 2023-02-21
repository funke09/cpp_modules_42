/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcherrad <zcherrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 22:11:23 by zcherrad          #+#    #+#             */
/*   Updated: 2023/02/21 02:06:45 by zcherrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"
#include "HumanA.hpp"
#include "HumanB.hpp"

// int main(int ac, char **av) 
// {
//     (void)av;
//     if(ac != 1) {
//         std::cout << "Usage: ./a.out" << std::endl;
//         return 1;
//     }
//     Weapon knife("knife");
//     HumanA john("John", knife);
//     john.attack();

//     Weapon gun("gun");
//     HumanB mike("Mike");
//     mike.setWeapon(gun);
//     mike.attack();

//     HumanB lucy("Lucy");
//     lucy.attack();

//     return 0;
// }

int main()
{
{
Weapon club = Weapon("crude spiked club");
HumanA bob("Bob", club);
bob.attack();
club.setType("some other type of club");
bob.attack();
}
{
Weapon club = Weapon("crude spiked club");
HumanB jim("Jim");
// jim.setWeapon(club);
jim.attack();
club.setType("some other type of club");
jim.attack();
}
return 0;
}
