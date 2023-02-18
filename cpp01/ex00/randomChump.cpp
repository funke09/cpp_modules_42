#include "Zombie.hpp"

void randomChump( std::string name )
{
    Zombie zombie;
    if(name == "")
        zombie.setName("stack zombie");
    else
        zombie.setName(name);
    zombie.announce();
}