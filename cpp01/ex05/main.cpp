/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcherrad <zcherrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 22:11:47 by zcherrad          #+#    #+#             */
/*   Updated: 2023/02/21 02:33:13 by zcherrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(int ac, char **av)
{
    (void)av;
    if(ac != 1)
    {
        std::cout << "Usage: ./a.out" << std::endl;
        return 1;
    }
    Harl harl;
    harl.complain("something else");
    harl.complain("DEBUG");
    harl.complain("INFO");
    harl.complain("WARNING");
    harl.complain("ERROR");
    return 0;
}