#include "Dog.hpp"
#include <iostream>

Dog::Dog() : Animal("Dog"), m_brain(new Brain()) {
    std::cout << "Dog constructor called!" << std::endl;
}

Dog::Dog(const Dog& other) : Animal(other), m_brain(new Brain(*other.m_brain)) {
    std::cout << "Dog copy constructor called!" << std::endl;
}

Dog::~Dog() {
    std::cout << "Dog destructor called!" << std::endl;
    delete m_brain;
}

Dog& Dog::operator=(const Dog& other) {
    if (this != &other) {
        Animal::operator=(other);
        *m_brain = *other.m_brain;
    }
    return *this;
}

void Dog::makeSound() const {
    std::cout << "Woof!" << std::endl;
}

void Dog::setIdea(const std::string& idea, int index) const {
    m_brain->setIdea(idea, index);
}

std::string Dog::getIdea(int index) const {
    return m_brain->getIdea(index);
}


