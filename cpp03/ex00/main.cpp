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
    clap.beRepaired(0);

    // copy.attack("enemy");
    // copy.attack("la");
    // copy.attack("si");
    // copy.attack("me");
    // copy.attack("to");

    return 0;
}