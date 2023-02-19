#include "Harl.hpp"

int main(int ac, char **av)
{
    (void)av;
    if(ac != 1)
    {
        std::cout << "Usage: ./a.out" << std::endl;
        return 1;
    }
    Harl harl;
    harl.complain("debug");
    harl.complain("info");
    harl.complain("warning");
    harl.complain("error");
    harl.complain("something else");
    return 0;
}