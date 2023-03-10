/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcherrad <zcherrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 22:10:47 by zcherrad          #+#    #+#             */
/*   Updated: 2023/02/22 03:32:40 by zcherrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>
# include <iomanip>
# include <string>


class Zombie
{
    private:
        std::string Name;

    public:
        Zombie();
        Zombie(std::string _name);
        void announce();
        ~Zombie();
};

Zombie* newZombie(std::string name);
void randomChump( std::string name );
#endif