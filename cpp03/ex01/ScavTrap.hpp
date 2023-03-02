#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include <iostream>
#include <string>
#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap {
    public:
    ScavTrap(std::string name);
    ScavTrap(const ScavTrap& other);
    ~ScavTrap();

    void attack(const std::string& target);
    void guardGate();

    private:
    static const int s_defaultHitPoints = 100;
    static const int s_defaultEnergyPoints = 50;
    static const int s_defaultAttackDamage = 20;
};

#endif
