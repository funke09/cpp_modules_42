#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <iostream>

class WrongAnimal {
public:
    WrongAnimal();
    WrongAnimal(const WrongAnimal& other);
    ~WrongAnimal();

    WrongAnimal& operator=(const WrongAnimal& other);

    void makeSound() const;

    std::string getType() const;

protected:
    std::string m_type;
};

#endif