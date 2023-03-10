/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcherrad <zcherrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 23:51:09 by zcherrad          #+#    #+#             */
/*   Updated: 2023/02/16 10:52:35 by zcherrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void)
{
    contactCount = 0;
}

PhoneBook::~PhoneBook(void)
{
}

PhoneBook::PhoneBook(std::string firstName, std::string lastName, std::string nickname, std::string phoneNumber, std::string darkestSecret)
{
   
    if (contactCount < MAX_CONTACTS) 
    {
        contacts[contactCount] = Contact(firstName, lastName, nickname, phoneNumber, darkestSecret);
        contactCount++;
    }
}

void PhoneBook::addContact(void)
{
    std::string firstName;
    std::string lastName;
    std::string nickname;
    std::string phoneNumber;
    std::string darkestSecret;

    std::cout << "**** ADDING CONTACT ****" << std::endl;
    std::cout << "First name: ";
    if(!std::getline(std::cin, firstName))
        return;
    std::cout << "Last name: ";
    if(!std::getline(std::cin, lastName))
        return;
    std::cout << "Nickname: ";
    if(!std::getline(std::cin, nickname))
        return;
    std::cout << "Phone number: ";
    if(!std::getline(std::cin, phoneNumber))
        return;
    std::cout << "Darkest secret: ";
    if(!std::getline(std::cin, darkestSecret))
        return;
    
    if (contactCount < MAX_CONTACTS) 
    {
        if(!firstName.empty() && !lastName.empty() && !nickname.empty() && !phoneNumber.empty() && !darkestSecret.empty())
        {
<<<<<<< HEAD
    
            std::cout << "enter one of three command:  ADD - SEARCH - EXIT " << std::endl;
            if(!(std::cin >> command))
                return(1);
            if(!std::cin.good())
                exit(1);
            if (command.compare("ADD") == 0)
                ft_add(info);
            else if (command.compare("SEARCH") == 0)
                ft_search(info);
            else if (command.compare("EXIT") == 0)
            {
                std::cout << "thella abogos/a" << std::endl;
                return 0;
            }
            else
            {
                std::cout << "wrong command" << std::endl;
            }
        }
   }
}
=======
            contacts[contactCount] = Contact(firstName, lastName, nickname, phoneNumber, darkestSecret);
            contactCount++;
        }
        else 
        {
            std::cout << "### ERROR: All fields must be filled ###" << std::endl;
        }
    }
  else
    {
        int oldestIndex = (contactCount) % MAX_CONTACTS;
        contacts[oldestIndex] = Contact(firstName, lastName, nickname, phoneNumber, darkestSecret);
        contactCount++;
    }

}

void PhoneBook::printContact(int idex) 
{
    std::cout << "**** DISPLAYING CONTACT ****" << std::endl;
    std::cout << "First name: " << contacts[idex].getFirstName() << std::endl;
    std::cout << "Last name: " << contacts[idex].getLastName() << std::endl;
    std::cout << "Nickname: " << contacts[idex].getNickname() << std::endl;
    std::cout << "Phone number: " << contacts[idex].getPhoneNumber() << std::endl;
    std::cout << "Darkest secret: " << contacts[idex].getDarkestSecret() << std::endl;

}


void PhoneBook::searchContact(void)
{
    std::string input;
    int index = 1;

    std::cout << "**** SEARCHING CONTACT ****" << std::endl;
    if(contactCount == 0)
    {
        std::cout << "### No contacts to display ###" << std::endl;
        return;
    }
    std::cout << "Enter the index of the contact you want to display: " << std::endl;
    std::cout << "     INDEX|  FIRSTNAME|   LASTNAME|   NICKNAME|" << std::endl;
    for (int i = 0; i < MAX_CONTACTS; i++)
    {
        std::cout << "         " << i + 1 << "|";
        if (contacts[i].getFirstName().length() > 10)
            std::cout << " " << contacts[i].getFirstName().substr(0, 9) << "." << "|";
        else
            std::cout << " " << contacts[i].getFirstName() << std::string(10 - contacts[i].getFirstName().length(), ' ') << "|";
        if (contacts[i].getLastName().length() > 10)
            std::cout << " " << contacts[i].getLastName().substr(0, 9) << "." << "|";
        else
            std::cout << " " << contacts[i].getLastName() << std::string(10 - contacts[i].getLastName().length(), ' ') << "|";
        if (contacts[i].getNickname().length() > 10)
            std::cout << " " << contacts[i].getNickname().substr(0, 9) << "." << "|";
        else
            std::cout << " " << contacts[i].getNickname() << std::string(10 - contacts[i].getNickname().length(), ' ') << "|";
        std::cout << std::endl;
    }
    std::getline(std::cin, input);
    if(input[0] && isdigit(input[0]))
    {
        index = std::stoi(input);
        if (index >= 1 && index <= contactCount)
        {
            printContact(index - 1);
        }
        else
        {
            std::cout << "Out of range !!" << std::endl;
        }
    }
    else
    {
        std::cout << "Invalid index" << std::endl;
    }
        
}
>>>>>>> a5faa3851cc0694f6e589998527b990f13e2b965
