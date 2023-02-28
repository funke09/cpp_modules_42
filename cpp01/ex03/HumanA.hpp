/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcherrad <zcherrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 22:11:14 by zcherrad          #+#    #+#             */
/*   Updated: 2023/02/21 15:54:31 by zcherrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_H
#define HUMANA_H

#include "Weapon.hpp"
#include <string>

class HumanA {
private:
    std::string _name;
    Weapon& _weapon;
public:
    HumanA(std::string name, Weapon& weapon);
    void attack() const;
};

#endif
