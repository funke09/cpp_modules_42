/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   randomChump.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcherrad <zcherrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 22:10:42 by zcherrad          #+#    #+#             */
/*   Updated: 2023/02/19 22:10:44 by zcherrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

void randomChump( std::string name )
{
    Zombie zombie;
    if(name == "")
        zombie.setName("stack zombie");
    else
        zombie.setName(name);
    zombie.announce();
}