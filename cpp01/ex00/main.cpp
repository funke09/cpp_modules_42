#include "Zombie.hpp"

int main()
{
    Zombie *zombie = newZombie("");
    zombie->announce();
    randomChump("");
    delete zombie;
    return (0);
}