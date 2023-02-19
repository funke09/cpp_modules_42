#ifndef HUMANA_H
#define HUMANA_H

#include "Weapon.hpp"
#include <string>

class HumanA {
public:
    HumanA(std::string name, Weapon& weapon);
    void attack() const;
private:
    std::string _name;
    Weapon& _weapon;
};

#endif
