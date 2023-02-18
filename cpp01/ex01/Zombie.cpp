#include "Zombie.hpp"

Zombie::Zombie()
{
    std::cout << "Zombie created" << std::endl;
}

Zombie::~Zombie()
{
    if(Name != "")
        std::cout << Name << " is destroyed" << std::endl;
    else
        std::cout << "Heap Zombie is destroyed" << std::endl;
}

void Zombie::announce()
{
    std::cout <<  Name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void Zombie::setName(std::string name)
{
    Name = name;
}