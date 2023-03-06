#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>

class Animal {
    public:
        Animal();
        Animal(const Animal& other);
        Animal(const std::string& type);
        virtual ~Animal();
        Animal& operator=(const Animal& other);
        virtual void makeSound() const;
        std::string getType() const;
    protected:
        std::string m_type;
};

#endif

