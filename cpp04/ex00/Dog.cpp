#include "Dog.hpp"

Dog::Dog() {
    m_type = "Dog";
    std::cout << "Dog default constructor called" << std::endl;
}

Dog::Dog(const Dog& other) : Animal(other) {
    std::cout << "Dog copy constructor called" << std::endl;
}

Dog::~Dog() {
    std::cout << "Dog destructor called" << std::endl;
}

std::string Dog::getType() const {
    return m_type;
}

void Dog::makeSound() const {
    std::cout << "Bark bark!" << std::endl;
}


