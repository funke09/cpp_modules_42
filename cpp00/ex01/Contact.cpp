/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcherrad <zcherrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 23:51:21 by zcherrad          #+#    #+#             */
/*   Updated: 2023/02/15 19:30:32 by zcherrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact()
{
}

Contact::~Contact()
{
}

Contact::Contact(std::string firstName, std::string lastName, std::string nickname, std::string phoneNumber, std::string darkestSecret)
{
        this->FirstName = firstName;
        this->LastName = lastName;
        this->Nickname = nickname;
        this->PhoneNumber = phoneNumber;
        this->DarkestSecret = darkestSecret;
}

void Contact::setFirstName(std::string FirstName)
{
    this->FirstName = FirstName;
}

void Contact::setLastName(std::string LastName)
{
    this->LastName = LastName;
}

void Contact::setNickname(std::string Nickname)
{
    this->Nickname = Nickname;
}

void Contact::setPhoneNumber(std::string PhoneNumber)
{
    this->PhoneNumber = PhoneNumber;
}

void Contact::setDarkestSecret(std::string DarkestSecret)
{
    this->DarkestSecret = DarkestSecret;
}

std::string Contact::getFirstName()
{
    return (this->FirstName);
}

std::string Contact::getLastName()
{
    return (this->LastName);
}

std::string Contact::getNickname()
{
    return (this->Nickname);
}

std::string Contact::getPhoneNumber()
{
    return (this->PhoneNumber);
}

std::string Contact::getDarkestSecret()
{
    return (this->DarkestSecret);
}
