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
    Fixed operator+(const Fixed &copy);
    Fixed operator-(const Fixed &copy);
    Fixed operator*(const Fixed &copy);
    Fixed operator/(const Fixed &copy);
    bool operator>(const Fixed &copy) const;
    bool operator<(const Fixed &copy) const;
    bool operator>=(const Fixed &copy) const;
    bool operator<=(const Fixed &copy) const;
    bool operator==(const Fixed &copy) const;
    bool operator!=(const Fixed &copy) const;
    Fixed operator++();
    Fixed operator++(int);
    Fixed operator--();
    Fixed operator--(int);
    static Fixed &min(Fixed &a, Fixed &b);
    static Fixed &max(Fixed &a, Fixed &b);
    static const Fixed &min(const Fixed &a, const Fixed &b);
    static const Fixed &max(const Fixed &a, const Fixed &b);
    ~Fixed();
};
std::ostream &operator<<(std::ostream &out, const Fixed &Fixed);

#endif