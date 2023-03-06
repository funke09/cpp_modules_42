#include "Cat.hpp"

Cat::Cat() {
    m_type = "Cat";
    m_brain = new Brain();
    std::cout << "Cat constructor called" << std::endl;
}

Cat::Cat(const Cat& other) : Animal(other) {
    m_brain = new Brain(*other.m_brain);
    std::cout << "Cat copy constructor called" << std::endl;
}

Cat::~Cat() {
    delete m_brain;
    std::cout << "Cat destructor called" << std::endl;
}

Cat& Cat::operator=(const Cat& other) {
    if (this != &other) {
        Animal::operator=(other);
        *m_brain = *other.m_brain;
    }
    std::cout << "Cat assignment operator called" << std::endl;
    return *this;
}

void Cat::makeSound() const {
    std::cout << "Meow" << std::endl;
}
