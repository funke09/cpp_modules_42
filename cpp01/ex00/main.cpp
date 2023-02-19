/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcherrad <zcherrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 22:10:33 by zcherrad          #+#    #+#             */
/*   Updated: 2023/02/19 22:10:35 by zcherrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(int ac, char **av)
{
    (void)av;
    if (ac != 1)
    {
        std::cout << "Usage: ./Zombie" << std::endl;
        return (1);
    }
    Zombie *zombie = newZombie("alo");
    zombie->announce();
    randomChump("new");
    delete zombie;
    return (0);
}