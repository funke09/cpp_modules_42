/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcherrad <zcherrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 17:16:38 by zcherrad          #+#    #+#             */
/*   Updated: 2023/03/03 17:16:40 by zcherrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void) 
{
    std::cout << "Default constructor ScavTrap called" << std::endl;
}

ScavTrap::ScavTrap(std::string name)
{
    this->_name = name;
    std::cout << "Constructor parameter ScavTrap called." << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& other)
{
    *this = other;
    std::cout << "Copy constructor ScavTrap called." << std::endl;
}

ScavTrap::~ScavTrap()
{
    std::cout << "Deconstructor ScavTrap is destroyed!\n";
}

void ScavTrap::attack(const std::string& target)
{
    if (_energyPoints <= 0 || _hitPoints <= 0) {
        std::cout << "ScavTrap " << _name << " has no energy points left!\n";
        return;
    }

    std::cout << "ScavTrap " << _name << " attacks " << target
              << ", causing " << _attackDamage << " points of damage!\n";

    _energyPoints--;
}

ScavTrap& ScavTrap::operator=(const ScavTrap &copy)
{
    this->_name = copy._name;
    this->_attackDamage = copy._attackDamage;
    this->_energyPoints = copy._energyPoints;
    this->_hitPoints = copy._hitPoints;
    return *this;
}

void ScavTrap::guardGate()
{
    std::cout << "ScavTrap is now in Gatekeeper mode." << std::endl;
}