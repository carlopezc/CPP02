/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlopez <carlopez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 19:31:31 by carlopez          #+#    #+#             */
/*   Updated: 2025/12/11 13:23:33 by carlopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : num(0)
{
    std::cout << "Default constructor called" << std::endl;
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed& other)
{
    *this = other;
    std::cout << "Copy constructor called" << std::endl;
}

Fixed::Fixed(const int value) : num(value << this->bits)
{
    std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float value)
{
    float newValue;
    
    //Same as value * 256
    newValue = value * (1 << this->bits);
    this->num = roundf(newValue);
    std::cout << "Float constructor called" << std::endl;
}

float Fixed::toFloat(void) const
{
    //Hacemos cast de uno de los numeros para que la division no sea entre ints y no desaparezcan los decimales en caso de que haya
    return ((float)this->num / (1 << this->bits));
}

int Fixed::toInt(void) const
{
    return (this->num >> this->bits);
}

Fixed& Fixed::operator=(const Fixed& other)
{
    if (this != &other)
        this->num = other.getRawBits();
    std::cout << "Copy assignment operator called" << std::endl;
    return (*this);
}

int Fixed::getRawBits(void) const
{
    std::cout << "getRawBits member function called" << std::endl;
    return (this->num);
}

void Fixed::setRawBits(int const raw)
{
    std::cout << "setRawBits member function called" << std::endl;
    this->num = raw;
}

std::ostream& operator<<(std::ostream& output, const Fixed& data)
{
    output << data.toFloat();
    return (output);
}

bool Fixed::operator>(const Fixed &other) const
{
    return (this->num > other.num);
}

bool Fixed::operator<(const Fixed &other) const
{
    return (this->num < other.num);
}

bool Fixed::operator>=(const Fixed &other) const
{
    return (this->num >= other.num);
}

bool Fixed::operator<=(const Fixed &other) const
{
    return (this->num <= other.num);
}

bool Fixed::operator!=(const Fixed &other) const
{
    return (this->num != other.num);
}

Fixed Fixed::operator+(const Fixed &other) const
{
    Fixed fixed;

    fixed.setRawBits(this->getRawBits() + other.getRawBits());
    return (fixed);   
}

Fixed Fixed::operator-(const Fixed &other) const
{
    Fixed fixed;
    
    fixed.setRawBits(this->getRawBits() - other.getRawBits());
    return (fixed);
}

Fixed Fixed::operator*(const Fixed &other) const
{
    Fixed fixed;
    long long temp = (long long)this->getRawBits() * (long long)other.getRawBits();
    fixed.setRawBits(temp >> 8);
    return (fixed);
}

Fixed Fixed::operator/(const Fixed &other) const
{
    Fixed fixed;
    long long temp = (long long)this->getRawBits() << 8;
    if (other.getRawBits() != 0)
        fixed.setRawBits(temp / other.getRawBits());
    return (fixed);
}

Fixed& Fixed::operator++(void)
{
    this->num = this->num + 1;
    return (*this);
}

Fixed Fixed::operator++(int)
{
    Fixed aux;

    aux = *this;
    this->num = this->num + 1;
    return (aux);
}

Fixed& Fixed::operator--(void)
{
    this->num = this->num - 1;
    return (*this);
}

Fixed Fixed::operator--(int)
{
    Fixed aux;

    aux = *this;
    this->num = this->num - 1;
    return (aux);
}

Fixed& Fixed::min(Fixed &a, Fixed &b)
{
    if (a < b)
        return (a);
    return (b);
}

const Fixed& Fixed::min(const Fixed &a, const Fixed &b)
{
    if (a < b)
        return (a);
    return (b);
}

Fixed& Fixed::max(Fixed &a, Fixed &b)
{
    if (a > b)
        return (a);
    return (b);
}

const Fixed& Fixed::max(const Fixed &a, const Fixed &b)
{
    if (a > b)
        return (a);
    return (b);
}
