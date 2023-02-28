/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcherrad <zcherrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 22:10:51 by zcherrad          #+#    #+#             */
/*   Updated: 2023/02/19 22:10:52 by zcherrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(int ac, char **av)
{
    (void)av;
    if(ac != 1) {
        std::cout << "Usage: ./Zombie" << std::endl;
        return 1;
    }
    Zombie* horde = zombieHorde(5, "Horde");
    for (int i = 0; i < 5; i++) {
        horde[i].announce();
    }
    delete[] horde;
    return 0;
}