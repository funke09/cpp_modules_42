#include "phone.hpp"

std::string Contact::getName()
{
    return this->name;
}

std::string Contact::getNumber()
{
    return this->number;
}

std::string Contact::getLastName()
{
    return this->last_name;
}

std::string Contact::getNickname()
{
    return this->nickname;
}


int main(int ac, char **av)
{
    (void)av;
    std::string all_info;
    std::string command;
    std::string name;
    
    Contact info[8];
    Contact contact("name", "number", "last_name", "nickname");

   if(ac != 1)
   {
       std::cout << "Usage: ./phoneBook " << std::endl;
       return 1;
   }
   else
   {
        while (1)
        {
    
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
