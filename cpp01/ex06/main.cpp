/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcherrad <zcherrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 22:11:59 by zcherrad          #+#    #+#             */
/*   Updated: 2023/02/19 22:12:01 by zcherrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(int ac, char **av)
{
    if(ac != 2)
    {
        std::cout << "Usage: ./a.out <level>" << std::endl;
        return 1;
    }
    Harl harl;
    harl.complain(av[1]);
    return 0;
}