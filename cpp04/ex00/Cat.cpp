#include "Cat.hpp"

Cat::Cat() {
    m_type = "Cat";
    std::cout << "Cat default constructor called" << std::endl;
}

Cat::Cat(const Cat& other) : Animal(other) {
    std::cout << "Cat copy constructor called" << std::endl;
}

Cat::~Cat() {
    std::cout << "Cat destructor called" << std::endl;
}

std::string Cat::getType() const {
    return m_type;
}

void Cat::makeSound() const {
    std::cout << "Meow meow!" << std::endl;
}

Cat& Cat::operator=(const Cat& other) {
    if (this != &other) {
        Animal::operator=(other);
    }
    std::cout << "Cat assignment operator called" << std::endl;
    return *this;
}
