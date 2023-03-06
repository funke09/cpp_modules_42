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

Animal::Animal(const std::string& type) : m_type(type) {
    std::cout << "Animal constructor called!" << std::endl;
}

Animal& Animal::operator=(const Animal& other) {
    if (this != &other) {
        m_type = other.m_type;
    }
    std::cout << "Animal assignment operator called" << std::endl;
    return *this;
}

