/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcherrad <zcherrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 17:15:50 by zcherrad          #+#    #+#             */
/*   Updated: 2023/03/03 17:15:53 by zcherrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(void) 
{
    std::cout << "Default constructor FragTrap called" << std::endl;
}

FragTrap::FragTrap(std::string name)
{
    this->_name = name;
    std::cout << "Constructor parameter FragTrap called." << std::endl;
}

FragTrap::FragTrap(const FragTrap& other)
{
    *this = other;
    std::cout << "Copy constructor FragTrap called." << std::endl;
}

FragTrap::~FragTrap()
{
    std::cout << "Deconstructor FragTrap is destroyed!\n";
}

void FragTrap::attack(const std::string& target)
{
    if (_energyPoints <= 0 || _hitPoints <= 0) {
        std::cout << "FragTrap " << _name << " has no energy points left!\n";
        return;
    }

    std::cout << "FragTrap " << _name << " attacks " << target
              << ", causing " << _attackDamage << " points of damage!\n";

    _energyPoints--;
}

FragTrap& FragTrap::operator=(const FragTrap &copy)
{
    this->_name = copy._name;
    this->_attackDamage = copy._attackDamage;
    this->_energyPoints = copy._energyPoints;
    this->_hitPoints = copy._hitPoints;
    return *this;
}

void FragTrap::highFivesGuys(void)
{
  std::cout << "Give me a high five! ( ＾◡＾)っ" << std::endl;
}
