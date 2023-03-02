#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>
#include <string>

class ClapTrap {
public:
  ClapTrap(std::string name);
  ClapTrap(const ClapTrap& other);
  virtual ~ClapTrap();

  void attack(const std::string& target);
  void takeDamage(unsigned int amount);
  void beRepaired(unsigned int amount);

  std::string getName() const;
  int getHitPoints() const;
  int getEnergyPoints() const;
  int getAttackDamage() const;

protected:
  std::string m_name;
  unsigned int m_hitPoints;
  unsigned int m_energyPoints;
  unsigned int m_attackDamage;
};

#endif  
 
