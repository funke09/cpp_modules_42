#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>
# include <iomanip>
# include <string>


class Zombie
{
    private:
        std::string Name;

    public:
        Zombie();
        ~Zombie();
        void announce();
        void setName(std::string name);
};

Zombie* newZombie(std::string name);
void randomChump( std::string name );
#endif