#include <iostream>
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main()
{
    ClapTrap clap("new");
    ScavTrap test("test");
    // ClapTrap copy(clap);

    // clap.attack("hello");
    // clap.attack("world");
    // clap.takeDamage(0);
    // clap.takeDamage(0);
    test.attack("00");
    for (int i = 0; i < 12; i++)
        clap.takeDamage(10);
    // copy.attack("enemy");
    // copy.attack("la");
    // copy.attack("si");
    // copy.attack("me");
    // copy.attack("to");

    return 0;
}