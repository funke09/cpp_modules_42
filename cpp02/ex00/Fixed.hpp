#ifndef FIXED_H
#define FIXED_H
#include <iostream>
class Fixed {
private:
    int _value;
    static const int fractional_bits = 8;

public:
    Fixed();
    Fixed(const Fixed& other);
    Fixed& operator=(const Fixed& other);
    ~Fixed();
    int     getRawBits() const;
    void    setRawBits(int raw);
};

#endif 
