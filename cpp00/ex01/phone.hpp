#ifndef PHONE_H
#define PHONE_H

#include <iostream>

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


#endif