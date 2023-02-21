/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcherrad <zcherrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 22:11:41 by zcherrad          #+#    #+#             */
/*   Updated: 2023/02/21 02:32:33 by zcherrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

void Harl::complain( std::string level )
{
    typedef void (Harl::*harl)();
    
    harl tab[4] = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};

    char    str[4][10] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    int i = 0;
    while (i < 4)
    {
        if (level == str[i])
            break ;
        i++;
    }
    switch (i)
    {
    case 0 :
       (this->*tab[i])();
        break ;
    case 1 :
        (this->*tab[i])();
        break ;
    case 2 :
        (this->*tab[i])();
        break ;
    case 3 :
        (this->*tab[i])();
        break ;
    default :
        std::cout << "[Probably complaining about insignificant problems] " << std::endl;
    }
}

void Harl::debug( void )
{
    std::cout << "[DEBUG]" << std::endl;
    std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!" << std::endl ;
}

void Harl::info( void )
{
    std::cout << "[INFO]" << std::endl;
    std::cout << "I cannot believe adding extra bacon costs more money." << std::endl;
    std::cout << "You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}

void Harl::warning( void )
{
    std::cout << "[WARNING]" << std::endl;
    std::cout << "think I deserve to have some extra bacon for free." << std::endl;
    std::cout << "I’ve been coming for years whereas you started working here since last month." << std::endl;
}

void Harl::error( void )
{
    std::cout << "[ERROR]" << std::endl;
    std::cout << "This is unacceptable! I want to speak to the manager now" << std::endl;
}
