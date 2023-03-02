#include "Fixed.hpp"

Fixed::Fixed() : FixedPoint(0){
    std::cout << "Default constructor called" << std::endl;
}

Fixed::~Fixed()
{
    std::cout << "Default destructor called" << std::endl;
}

Fixed::Fixed(const Fixed &copy)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = copy;
}

Fixed::Fixed(const int Fixed)
{
    std::cout << "Int constructor called" << std::endl;
    this->FixedPoint = Fixed << this->BitCount;
}

float Fixed::toFloat( void ) const
{
    return ((float)this->FixedPoint / (1 << this->BitCount));
}

Fixed::Fixed(const float Fixed)
{
    std::cout << "Float constructor called" << std::endl;
    this->FixedPoint = roundf(Fixed * (1 << this->BitCount));
}

int Fixed::toInt( void ) const
{
    return (this->FixedPoint >> this->BitCount);
}

int Fixed::getRawBits( void ) const
{
    std::cout << "getRawBits member function called" << std::endl;
    return (this->FixedPoint);
}

void Fixed::setRawBits( int const raw )
{
    std::cout << "setRawBits member function called" << std::endl;
    this->FixedPoint = raw;
}

Fixed &Fixed::operator=(const Fixed &copy)
{
    std::cout << "Copy assignment operator called" << std::endl;
    this->FixedPoint = copy.getRawBits();
    return (*this);
}

std::ostream &operator<<(std::ostream &out, const Fixed &Fixed)
{
    out << Fixed.toFloat();
    return (out);
}