#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"

class Cat : public Animal {
public:
    Cat();
    Cat(const Cat& other);
    ~Cat();
    std::string getType() const;
    void makeSound() const;
};

#endif
