#include <iostream>
#include "ClapTrap.hpp"

// int main()
// {
//     ClapTrap clap("new");
//     ClapTrap copy(clap);

//     clap.attack("hello");
//     clap.attack("world");
//     clap.takeDamage(0);
//     clap.takeDamage(0);
//     clap.beRepaired(0);


//     return 0;
// }

#include "ScavTrap.hpp"

int main() {
  ScavTrap scav("Claptrap");

  scav.attack("enemy");
  scav.takeDamage(30);
  scav.beRepaired(20);
  scav.guardGate();

  return 0;
}
