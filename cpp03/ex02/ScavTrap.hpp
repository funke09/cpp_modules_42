#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include <iostream>
#include <string>
#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap {
    public:
        ScavTrap();
        ScavTrap(std::string name);
        ScavTrap(const ScavTrap& other);
        ScavTrap &operator=(const ScavTrap &copy);
        ~ScavTrap();
        void attack(const std::string& target);
        void guardGate();
};

#endif
