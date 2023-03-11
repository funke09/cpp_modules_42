#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal {
    public:
        Dog();
        Dog(const Dog& other);
        ~Dog();

        Dog& operator=(const Dog& other);

        void makeSound() const;

        void setIdea(const std::string& idea, int index) const;
        std::string getIdea(int index) const;

    private:
        Brain* m_brain;
};

#endif

