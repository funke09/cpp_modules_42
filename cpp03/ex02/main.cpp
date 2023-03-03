/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcherrad <zcherrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 17:16:05 by zcherrad          #+#    #+#             */
/*   Updated: 2023/03/03 17:16:07 by zcherrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

int main()
{
  FragTrap New("00");
  ScavTrap Scav("01");
  ClapTrap Clap("02");
  

  Scav.attack("other");
  New.highFivesGuys();

  New.attack("wow");
  return 0;
}
