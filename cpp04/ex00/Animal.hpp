#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>
#include <string>

class Animal {
public:
    Animal();
    Animal(const Animal& other);
    virtual ~Animal();
    std::string getType() const;
    virtual void makeSound() const;
    Animal& operator=(const Animal& other);

protected:
    std::string m_type;
};

#endif
