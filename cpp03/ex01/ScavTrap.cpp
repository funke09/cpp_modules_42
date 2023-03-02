#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string name) : ClapTrap(name) {
    m_hitPoints = s_defaultHitPoints;
    m_energyPoints = s_defaultEnergyPoints;
    m_attackDamage = s_defaultAttackDamage;
    std::cout << "A new ScavTrap named " << m_name << " has been created!\n";
}

ScavTrap::ScavTrap(const ScavTrap& other) : ClapTrap(other) {}

ScavTrap::~ScavTrap() {
    std::cout << "ScavTrap " << m_name << " has been destroyed!\n";
}

void ScavTrap::attack(const std::string& target) {
    if (m_energyPoints >= 1) {
        std::cout << "ScavTrap " << m_name << " attacks " << target << ", causing " << m_attackDamage << " points of damage!\n";
        m_energyPoints--;
    } else {
        std::cout << "ScavTrap " << m_name << " has no energy points left to attack!\n";
    }
}

void ScavTrap::guardGate() {
    std::cout << "ScavTrap " << m_name << " is now guarding the gate!\n";
}
