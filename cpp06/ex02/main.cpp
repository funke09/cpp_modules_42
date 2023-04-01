#include "Base.hpp"

extern Base* generate();
extern void identify(Base* p);
extern void identify(Base& p);

int main() {
    Base* base = generate();
    Base& base_ref = *base;

    identify(&base_ref); 

    identify(base_ref); 



    identify(base); 

    identify(*base); 
    delete base;
    return 0;
}

