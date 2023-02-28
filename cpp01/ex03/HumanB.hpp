/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcherrad <zcherrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 22:11:20 by zcherrad          #+#    #+#             */
/*   Updated: 2023/02/20 18:59:47 by zcherrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_H
#define HUMANB_H

#include "Weapon.hpp"
#include <string>

class HumanB {
private:
    std::string _name;
    Weapon* _weapon;
public:
    HumanB(std::string name);
    void setWeapon(Weapon& weapon);
    void attack() const;
};

#endif