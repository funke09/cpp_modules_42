/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone2.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcherrad <zcherrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 21:47:41 by zcherrad          #+#    #+#             */
/*   Updated: 2023/02/05 21:48:31 by zcherrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

/**
 * It takes a string and returns a string with all the letters in uppercase
 * 
 * @param ac the number of arguments passed to the program
 * @param av array of strings
 * 
 * @return The program is returning the uppercase version of the arguments passed to it.
 */
int main(int ac, char **av)
{
    if (ac > 1)
    {
        for (int i = 1; i < ac; i++)
        {
            for (int j = 0; av[i][j]; j++)
            {
                std::cout << (char)toupper(av[i][j]);
            }
                if (i < ac - 1)
				    std::cout << ' ';
        }
        std::cout << std::endl;
    }
    else
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
    return 0;
}