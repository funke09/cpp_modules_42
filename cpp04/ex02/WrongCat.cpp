#include "WrongCat.hpp"

WrongCat::WrongCat() {
    m_type = "WrongCat";
    std::cout << "WrongCat default constructor called" << std::endl;
}

WrongCat::WrongCat(const WrongCat& other) {
    *this = other;
    std::cout << "WrongCat copy constructor called" << std::endl;
}

WrongCat::~WrongCat() {
    std::cout << "WrongCat destructor called" << std::endl;
}

WrongCat& WrongCat::operator=(const WrongCat& other) {
    if (this != &other) {
        m_type = other.m_type;
    }
    std::cout << "WrongCat assignment operator called" << std::endl;
    return *this;
}
void WrongCat::makeSound() const {
    std::cout << "WrongCat sound" << std::endl;
}
