/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcherrad <zcherrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 22:11:01 by zcherrad          #+#    #+#             */
/*   Updated: 2023/02/19 22:11:03 by zcherrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name) {
    Zombie* horde = new Zombie[N];

    for (int i = 0; i < N; i++) {
        horde[i].setName(name + std::to_string(i));
    }

    return horde;
}
