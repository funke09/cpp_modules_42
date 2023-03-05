#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>
#include <string>

class Animal {
public:
    Animal();
    Animal(const Animal& other);
    virtual ~Animal();
    virtual std::string getType() const;
    virtual void makeSound() const;

protected:
    std::string m_type;
};

#endif