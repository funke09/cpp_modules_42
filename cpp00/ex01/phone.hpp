#ifndef PHONE_H
#define PHONE_H

#include <iostream>
#include <strstream>
#include <streambuf>

class Contact
{
private:
    std::string name;
    std::string number;
    std::string last_name;
    std::string nickname;
public:
    Contact();
    Contact(std::string name, std::string number, std::string last_name, std::string nickname);
    std::string getNumber();
    std::string getLastName();
    std::string getNickname();
    void ft_add(Contact *all_info);
    void ft_search(Contact *all_info);
    std::string getName();
    ~Contact();
};

Contact::Contact(std::string name, std::string number, std::string last_name, std::string nickname)
{
    this->name = name;
    this->number = number;
    this->last_name = last_name;
    this->nickname = nickname;
}

Contact::Contact()
{
    this->name = "";
    this->number = "";
    this->last_name = "";
    this->nickname = "";
}

Contact::~Contact()
{

}

unsigned int array_size(Contact *all_info)
{
    unsigned int i = 0;

    while (all_info[i].getName().compare("") != 0 && i < 8)
        i++;
    return i;
}

void ft_add(Contact *all_info)
{
    std::cout << "ADD CONTACT" << std::endl;

    std::cout << "enter name: ";
    std::string name;
    if(!(std::cin >> name))
        return ;
    std::cout << "enter number: ";
    std::string number;
    if(!(std::cin >> number))
        return ;
    std::cout << "enter last name: ";
    std::string last_name;
    if(!(std::cin >> last_name))
        return ;
    std::cout << "enter nickname: ";
    std::string nickname;
    if(!(std::cin >> nickname))
        return ;
    Contact contact(name, number, last_name, nickname);
    unsigned int size = array_size(all_info);
    if (size < 8)
    {
        all_info[size] = contact;
        std::cout << "contact added" << std::endl;
    }
    else
    {
        // std::cout << "phonebook is full" << std::endl;
        // if phonebook is full, we need to delete the oldest contact and add the new one
        for (unsigned int i = 0; i < 8 - 1; i++)
        {
            all_info[i] = all_info[i + 1];
        }
        all_info[7] = contact;
        std::cout << "oldest contact deleted, new contact added" << std::endl;

    }
}


void ft_search(Contact *all_info)
{

    std::cout << "all contacts you have :" << std::endl;
    unsigned int size = array_size(all_info);
    if (size == 0)
    {
        std::cout << "phonebook is empty :(" << std::endl;
        return ;
    }
    std::cout << "     index| first name| last name|  nickname" << std::endl;
    for (unsigned int i = 0; i < size; i++)
    {
        std::cout << "         " << i << "|";
        if (all_info[i].getName().length() > 10)
            std::cout << all_info[i].getName().substr(0, 9) << "." << "|";
        else
            std::cout << all_info[i].getName() << std::string(10 - all_info[i].getName().length(), ' ') << "|";
        if (all_info[i].getLastName().length() > 10)
            std::cout << all_info[i].getLastName().substr(0, 9) << "." << "|";
        else
            std::cout << all_info[i].getLastName() << std::string(10 - all_info[i].getLastName().length(), ' ') << "|";
        if (all_info[i].getNickname().length() > 10)
            std::cout << all_info[i].getNickname().substr(0, 9) << "." << "|";
        else
            std::cout << all_info[i].getNickname() << std::string(10 - all_info[i].getNickname().length(), ' ') << "|";
        std::cout << std::endl;
    }
    std::cout << "enter index of contact you wanna see: ";
    unsigned int index;
    if(!(std::cin >> index))
        return ;
    if (index < size)
    {
        std::cout << "name: " << all_info[index].getName() << std::endl;
        std::cout << "number: " << all_info[index].getNumber() << std::endl;
        std::cout << "last name: " << all_info[index].getLastName() << std::endl;
        std::cout << "nickname: " << all_info[index].getNickname() << std::endl;
    }
    else
    {
        std::cout << "wrong index" << std::endl;
    }
}

#endif