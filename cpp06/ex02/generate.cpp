#include <cstdlib>
#include <ctime>
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base* generate() {
    std::srand(std::time(0));
    int rand_num = std::rand() % 3;
    switch (rand_num) {
        case 0:
            return new A();
        case 1:
            return new B();
        default:
            return new C();
    }
}
