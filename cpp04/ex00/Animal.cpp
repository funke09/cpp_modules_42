#include "Animal.hpp"

Animal::Animal() : m_type("Animal") {
    std::cout << "Animal default constructor called" << std::endl;
}

Animal::Animal(const Animal& other) : m_type(other.m_type) {
    std::cout << "Animal copy constructor called" << std::endl;
}

Animal::~Animal() {
    std::cout << "Animal destructor called" << std::endl;
}

std::string Animal::getType() const {
    return m_type;
}

void Animal::makeSound() const {
    std::cout << "Animal sound" << std::endl;
}


