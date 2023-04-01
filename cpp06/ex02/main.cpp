#include "Base.hpp"

extern Base* generate();
extern void identify(Base* p);
extern void identify(Base& p);

int main() {
    Base* obj = generate();
    identify(obj);
    identify(*obj);
    delete obj;
    return 0;
}

