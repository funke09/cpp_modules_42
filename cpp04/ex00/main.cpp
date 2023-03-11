#include <iostream>
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
    const Animal* cat = new Cat();

    cat->makeSound();    // const Animal* meta = new Animal();
    // const WrongAnimal *wrong = new WrongAnimal();
    // const WrongAnimal *wrongCat = new WrongCat();
    // const Animal* j = new Dog();
    // const Animal* i = new Cat();
    // i->Animal::makeSound();
    // std::cout << wrong->getType() << " " << std::endl;
    // std::cout << wrongCat->getType() << " " << std::endl;
    // std::cout << j->getType() << " " << std::endl;
    // std::cout << i->getType() << " " << std::endl;
    // wrong->makeSound();
    // wrongCat->makeSound();
    // i->makeSound(); //will output the cat sound!
    // j->makeSound();
    // meta->makeSound();

    // delete meta;
    // delete j;
    // delete i;
    // delete wrong;
    // delete wrongCat;
    return 0;
}
