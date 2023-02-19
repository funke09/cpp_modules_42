#include "Harl.hpp"

void Harl::complain( std::string level )
{
    if (level == "debug")
        debug();
    else if (level == "info")
        info();
    else if (level == "warning")
        warning();
    else if (level == "error")
        error();
    else
        std::cout << "I can't do anything with " << level << std::endl;
}

void Harl::debug( void )
{
    std::cout << "I'm a bug!" << std::endl;
}

void Harl::info( void )
{
    std::cout << "I'm a piece of information!" << std::endl;
}

void Harl::warning( void )
{
    std::cout << "I'm a warning!" << std::endl;
}

void Harl::error( void )
{
    std::cout << "I'm an error!" << std::endl;
}
