/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcherrad <zcherrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 23:51:04 by zcherrad          #+#    #+#             */
/*   Updated: 2023/02/15 19:08:55 by zcherrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <iostream>
# include "Contact.hpp"
#define MAX_CONTACTS 8

class PhoneBook
{
    public:
        PhoneBook(void);
        ~PhoneBook(void);
        PhoneBook(std::string firstName, std::string lastName, std::string nickname, std::string phoneNumber, std::string darkestSecret);
        int            contactCount;
        void		addContact();
        void		searchContact();
        void		printContact(int index);

    private:
        Contact        contacts[8];
};

#endif