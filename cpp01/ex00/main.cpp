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