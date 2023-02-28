/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcherrad <zcherrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 22:11:31 by zcherrad          #+#    #+#             */
/*   Updated: 2023/02/20 18:56:21 by zcherrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_H
#define WEAPON_H
#include <iostream>
#include <string>

class Weapon {
private:
    std::string _type;
public:
    Weapon(std::string type);
    const std::string& getType() const;
    void setType(const std::string& type);
};

#endif
