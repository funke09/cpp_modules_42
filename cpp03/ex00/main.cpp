/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcherrad <zcherrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 17:16:53 by zcherrad          #+#    #+#             */
/*   Updated: 2023/03/03 17:16:55 by zcherrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ClapTrap.hpp"

int main()
{
    ClapTrap clap("new");
    ClapTrap copy(clap);

    clap.attack("hello");
    clap.attack("world");
    clap.takeDamage(0);
    clap.takeDamage(0);
    for (int i = 0; i < 12; i++)
        clap.takeDamage(10);
    // copy.attack("enemy");
    // copy.attack("la");
    // copy.attack("si");
    // copy.attack("me");
    // copy.attack("to");

    return 0;
}