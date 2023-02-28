#ifndef FIXED_HPP
#define FIXED_HPP
#include <iostream>
#include <cmath>
class Fixed
{
    private:
    int FixedPoint;
    static const int BitCount = 8;


    public:
    Fixed();
    Fixed(const Fixed &copy);
    Fixed(const int Fixed);
    Fixed(const float Fixed);
    float toFloat( void ) const;
    int toInt( void ) const;
    Fixed &operator=(const Fixed &copy);
    int getRawBits( void ) const;
    void setRawBits( int const raw );
    ~Fixed();
};
std::ostream &operator<<(std::ostream &out, const Fixed &Fixed);

#endif