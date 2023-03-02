/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcherrad <zcherrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 23:01:18 by zcherrad          #+#    #+#             */
/*   Updated: 2023/02/28 23:01:20 by zcherrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : FixedPoint(0){
    
}

Fixed::~Fixed()
{
}

Fixed::Fixed(const Fixed &copy)
{
    *this = copy;
}

Fixed::Fixed(const int Fixed)
{
    this->FixedPoint = Fixed << this->BitCount;
}

float Fixed::toFloat( void ) const
{
    return ((float)this->FixedPoint / (1 << this->BitCount));
}

Fixed::Fixed(const float Fixed)
{
    this->FixedPoint = roundf(Fixed * (1 << this->BitCount));
}

int Fixed::toInt( void ) const
{
    return (this->FixedPoint >> this->BitCount);
}

int Fixed::getRawBits( void ) const
{
    return (this->FixedPoint);
}

void Fixed::setRawBits( int const raw )
{
    this->FixedPoint = raw;
}

Fixed &Fixed::operator=(const Fixed &copy)
{
    this->FixedPoint = copy.getRawBits();
    return (*this);
}

std::ostream &operator<<(std::ostream &out, const Fixed &Fixed)
{
    out << Fixed.toFloat();
    return (out);
}