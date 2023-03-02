#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name) :
  m_name(name),
  m_hitPoints(100),
  m_energyPoints(50),
  m_attackDamage(20) {
  std::cout << "A new ClapTrap named " << m_name << " has been created!\n";
}

ClapTrap::ClapTrap(const ClapTrap& other) {
  m_name = other.m_name;
  m_hitPoints = other.m_hitPoints;
  m_energyPoints = other.m_energyPoints;
  m_attackDamage = other.m_attackDamage;
}

ClapTrap::~ClapTrap() {
  std::cout << "ClapTrap " << m_name << " has been destroyed!\n";
}

void ClapTrap::attack(const std::string& target) {
  if (m_energyPoints >= 1) {
    std::cout << "ClapTrap " << m_name << " attacks " << target << ", causing " << m_attackDamage << " points of damage!\n";
    m_energyPoints--;
  } else {
    std::cout << "ClapTrap " << m_name << " has no energy points left to attack!\n";
  }
}

void ClapTrap::takeDamage(unsigned int amount) {
  if (m_hitPoints >= amount) {
    m_hitPoints -= amount;
    std::cout << "ClapTrap " << m_name << " takes " << amount << " points of damage! Current hit points: " << m_hitPoints << "\n";
  } else {
    m_hitPoints = 0;
    std::cout << "ClapTrap " << m_name << " takes " << amount << " points of damage and is destroyed!\n";
  }
}

void ClapTrap::beRepaired(unsigned int amount) {
  if (m_hitPoints == 0) {
    std::cout << "ClapTrap " << m_name << " cannot be repaired because it is destroyed!\n";
  } else if (m_energyPoints >= 1) {
    m_hitPoints += amount;
    if (m_hitPoints > 100) m_hitPoints = 100;
    std::cout << "ClapTrap " << m_name << " has been repaired for " << amount << " hit points! Current hit points: " << m_hitPoints << "\n";
  }
}

std::string ClapTrap::getName() const {
  return m_name;
}

int ClapTrap::getHitPoints() const {
  return m_hitPoints;
}

int ClapTrap::getEnergyPoints() const {
  return m_energyPoints;
}

int ClapTrap::getAttackDamage() const {
  return m_attackDamage;
}
