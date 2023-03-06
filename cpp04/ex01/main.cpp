// #include <iostream>
// #include "Animal.hpp"
// #include "Dog.hpp"
// #include "Cat.hpp"
// #include "WrongAnimal.hpp"
// #include "WrongCat.hpp"

// int main()
// {
//     const Animal* meta = new Animal();
//     const WrongAnimal *wrong = new WrongAnimal();
//     const WrongAnimal *wrongCat = new WrongCat();
//     const Animal* j = new Dog();
//     const Animal* i = new Cat();
//     i->Animal::makeSound();
//     std::cout << wrong->getType() << " " << std::endl;
//     std::cout << wrongCat->getType() << " " << std::endl;
//     std::cout << j->getType() << " " << std::endl;
//     std::cout << i->getType() << " " << std::endl;
//     wrong->makeSound();
//     wrongCat->makeSound();
//     i->makeSound(); //will output the cat sound!
//     j->makeSound();
//     meta->makeSound();

//     // delete meta;
//     // delete j;
//     // delete i;
//     // delete wrong;
//     // delete wrongCat;
//     return 0;
// }

#include <iostream>
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main() {
    Animal* animals[4];
    animals[0] = new Dog();
    animals[1] = new Dog();
    animals[2] = new Cat();
    animals[3] = new Cat();

    for (int i = 0; i < 4; i++) {
        animals[i]->makeSound();
        delete animals[i];
    }

    return 0;
}
