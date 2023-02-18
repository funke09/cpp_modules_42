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

Zombie* zombieHorde( int N, std::string name );

#endif