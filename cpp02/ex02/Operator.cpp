#include "Fixed.hpp"

Fixed Fixed::operator+(const Fixed &other)
{
    Fixed New(this->toFloat() + other.toFloat());
    return (New);
}

Fixed Fixed::operator-(const Fixed &other)
{
    Fixed New(this->toFloat() - other.toFloat());
    return (New);
}

Fixed Fixed::operator*(const Fixed &other)
{
    Fixed New(this->toFloat() * other.toFloat());
    return (New);
}

Fixed Fixed::operator/(const Fixed &other)
{
    Fixed New(this->toFloat() / other.toFloat());
    return (New);
}

Fixed Fixed::operator++()
{
    this->FixedPoint += 1;
    return (*this);
}

Fixed Fixed::operator++(int)
{
    Fixed temp = *this;

    this->FixedPoint += 1;

    return temp;
}

Fixed Fixed::operator--()
{
    this->FixedPoint -= 1 ;
    return (*this);
}

Fixed Fixed::operator--(int)
{
    Fixed temp = *this;

    this->FixedPoint -= 1;

    return temp;
}

bool Fixed::operator>(const Fixed &copy) const
{
    return (this->toFloat() > copy.toFloat());
}

bool Fixed::operator<(const Fixed &copy) const
{
    return (this->toFloat() < copy.toFloat());
}

bool Fixed::operator>=(const Fixed &copy) const
{
    return (this->toFloat() >= copy.toFloat());
}

bool Fixed::operator<=(const Fixed &copy) const
{
    return (this->toFloat() <= copy.toFloat());
}

bool Fixed::operator==(const Fixed &copy) const
{
    return (this->toFloat() == copy.toFloat());
}

bool Fixed::operator!=(const Fixed &copy) const
{
    return (this->toFloat() != copy.toFloat());
}


// Static member function to return the minimum of two Fixed values
Fixed& Fixed::min(Fixed& a, Fixed& b) {
    return a < b ? a : b;
}

// Static member function to return the maximum of two Fixed values
Fixed& Fixed::max(Fixed& a, Fixed& b) {
    return a > b ? a : b;
}

// Static member function to return the minimum of two constant Fixed values
const Fixed& Fixed::min(const Fixed& a, const Fixed& b) {
    return a < b ? a : b;
}

// Static member function to return the maximum of two constant Fixed values
const Fixed& Fixed::max(const Fixed& a, const Fixed& b) {
    return a > b ? a : b;
}



