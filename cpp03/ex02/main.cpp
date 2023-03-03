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
