#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal {
   public:
    Cat();
    Cat(const Cat& other);
    ~Cat();

    Cat& operator=(const Cat& other);

    void makeSound() const;

   private:
    Brain* m_brain;
};

#endif

