#include <iostream>
#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name) :
    _name(name),
    _hitPoints(10),
    _energyPoints(10),
    _attackDamage(0)
{
    std::cout << "ClapTrap " << _name << " is born!\n";
}

ClapTrap::ClapTrap(const ClapTrap& other) :
    _name(other._name + "_copy"),
    _hitPoints(other._hitPoints),
    _energyPoints(other._energyPoints),
    _attackDamage(other._attackDamage)
{
    std::cout << "ClapTrap " << _name << " is born as a copy!\n";
}

ClapTrap::~ClapTrap()
{
    std::cout << "ClapTrap " << _name << " is destroyed!\n";
}

void ClapTrap::attack(const std::string& target)
{
    if (_energyPoints == 0) {
        std::cout << "ClapTrap " << _name << " has no energy points left!\n";
        return;
    }

    std::cout << "ClapTrap " << _name << " attacks " << target
              << ", causing " << _attackDamage << " points of damage!\n";

    _energyPoints--;
}

void ClapTrap::takeDamage(unsigned int amount)
{
    if (_hitPoints == 0) {
        std::cout << "ClapTrap " << _name << " has no hit points left!\n";
        return;
    }

    std::cout << "ClapTrap " << _name << " takes " << amount << " points of damage!\n";

    if (amount >= _hitPoints) {
        _hitPoints = 0;
        std::cout << "ClapTrap " << _name << " has been destroyed!\n";
    }
    else {
        _hitPoints -= amount;
    }
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (_energyPoints == 0) {
        std::cout << "ClapTrap " << _name << " has no energy points left!\n";
        return;
    }

    std::cout << "ClapTrap " << _name << " repairs itself, gaining " << amount << " hit points!\n";

    _energyPoints--;
    _hitPoints += amount;
}


