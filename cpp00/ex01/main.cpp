/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcherrad <zcherrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 23:51:14 by zcherrad          #+#    #+#             */
/*   Updated: 2023/02/14 23:51:15 by zcherrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int main(void)
{
    PhoneBook phoneBook;
    std::string command;

    while (1)
    {
        std::cout << "Enter a command: " << std::endl;
        std::cout << "ADD : Add a new contact" << std::endl;
        std::cout << "SEARCH : Search a contact" << std::endl;
        std::cout << "EXIT : Get out !!" << std::endl;
        if(!std::cin.good())
            break ;
        std::getline(std::cin, command);
        if (command == "EXIT")
        {
            std::cout << "Bye bye" << std::endl;
            break ;
        }
        else if (command == "ADD")
            phoneBook.addContact();
        else if (command == "SEARCH")
            phoneBook.searchContact();
        else
            std::cout << "Invalid command" << std::endl;
    }
    return (0);
}