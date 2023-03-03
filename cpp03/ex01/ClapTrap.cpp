/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcherrad <zcherrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 17:16:25 by zcherrad          #+#    #+#             */
/*   Updated: 2023/03/03 17:16:27 by zcherrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void) :
     _name("Unknown"),
    _hitPoints(100),
    _energyPoints(50),
    _attackDamage(20)
{
    std::cout << "Default constructor ClapTrap called" << std::endl;
}

ClapTrap::ClapTrap(std::string name) :
    _name(name),
    _hitPoints(100),
    _energyPoints(50),
    _attackDamage(20)
{
    std::cout << "Constructor parameter ClapTrap " << _name << " called." << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other)
{
    *this = other;
    std::cout << "Copy constructor ClapTrap" << _name << " called." << std::endl;
}

ClapTrap::~ClapTrap()
{
    std::cout << "Deconstructor ClapTrap" << _name << " is destroyed!\n";
}

void ClapTrap::attack(const std::string& target)
{
    if (_energyPoints <= 0 || _hitPoints <= 0) {
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
    if (_energyPoints <= 0 || _hitPoints <= 0) {
        std::cout << "ClapTrap " << _name << " has no energy points left!\n";
        return;
    }

    std::cout << "ClapTrap " << _name << " repairs itself, gaining " << amount << " hit points!\n";

    _energyPoints--;
    _hitPoints += amount;
}

ClapTrap& ClapTrap::operator=(const ClapTrap &copy)
{
    this->_attackDamage = copy._attackDamage;
    this->_energyPoints = copy._energyPoints;
    this->_hitPoints = copy._hitPoints;
    this->_name = copy._name;
    return *this;
}



