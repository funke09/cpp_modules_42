#include "phone.hpp"

std::string Contact::getName()
{
    return this->name;
}

std::string Contact::getNumber()
{
    return this->number;
}

void ft_add(Contact all_info[])
{
    std::cout << "enter name: ";
    std::string name;
    std::cin >> name;
    std::cout << "enter number: ";
    std::string number;
    std::cin >> number;
    std::cout << "enter last name: ";
    std::string last_name;
    std::cin >> last_name;
    std::cout << "enter nickname: ";
    std::string nickname;
    std::cin >> nickname;
    Contact contact(name, number, last_name, nickname);
    // int size = *(&all_info + 1) - all_info;

    // printf("%d", size);
    if (size < 8)
    {
        all_info[size] = contact;
        std::cout << "contact added" << std::endl;
    }
    else
        std::cout << "phonebook is full" << std::endl;
}


int main(int ac, char **av)
{
    (void)av;
    std::string all_info;
    std::string command;
    std::string name;
    
    Contact info[8];
    // Contact contact("name", "number", "last_name", "nickname");

   if(ac != 1)
   {
       std::cout << "Usage: ./phoneBook " << std::endl;
       return 1;
   }
   else
   {
        while (1)
        {
            std::cout << "enter one of three command:  ADD - SEARCH - EXIT  ";
            std::cin >> command;
            if (command.compare("ADD") == 0)
            {
                std::cout << "add" << std::endl;
                ft_add(info);
            }
            else if (command.compare("SEARCH") == 0)
            {
                std::cout << "enter some information about contact:" << std::endl;
                std::string info;
                std::cin >> info;
                // if(name.compare(info) == 0)
                //     std::cout << "name: " << contact.getName() << std::endl;
                // else
                //     std::cout << "no such contact" << std::endl;
            }
            else if (command.compare("EXIT") == 0)
            {
                std::cout << "exit" << std::endl;
                return 0;
            }
            else
            {
                std::cout << "wrong command" << std::endl;
            }
        }

   }

}

// a pro