#include "Animal.hpp"

Animal::Animal()
{
    std::cout << "Animal constructor called" << std::endl;
    this->_type = "Animal";
}

Animal::Animal(Animal const & src)
{
    std::cout << "Animal copy constructor called" << std::endl;
    *this = src;
}

Animal::~Animal()
{
    std::cout << "Animal destructor called" << std::endl;
}

Animal &		Animal::operator=(Animal const & rhs)
{
    std::cout << "Animal assignation operator called" << std::endl;
    if (this != &rhs)
        this->_type = rhs._type;
    return *this;
}

void	Animal::makeSound() const
{
    std::cout << "Animal sound" << std::endl;
}

std::string		Animal::getType() const
{
    return this->_type;
}

