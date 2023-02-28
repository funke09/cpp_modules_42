/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcherrad <zcherrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 23:51:14 by zcherrad          #+#    #+#             */
/*   Updated: 2023/02/15 00:04:19 by zcherrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int main(int ac, char **av)
{
    PhoneBook phoneBook;
    std::string command;
    (void)av;
    

    if (ac != 1)
    {
        std::cout << "Usage: ./phonebook" << std::endl;
        return (1);
    }
    else
    {  
        while (1)
        {
            if(!std::cin.good())
                break ;
            std::cout << "Enter a command: " << std::endl;
            std::cout << "ADD : Add a new contact" << std::endl;
            std::cout << "SEARCH : Search a contact" << std::endl;
            std::cout << "EXIT : Get out !!" << std::endl;
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
            else if(!command.empty())
                std::cout << "Invalid command" << std::endl;
        }
    }
    return (0);
}