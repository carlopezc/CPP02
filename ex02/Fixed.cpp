/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlopez <carlopez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 19:31:31 by carlopez          #+#    #+#             */
/*   Updated: 2025/12/15 17:33:49 by carlopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : _num(0)
{
    std::cout << "Default constructor called" << std::endl;
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed& other)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = other;
}

Fixed::Fixed(const int value) : _num(value << this->_bits)
{
    std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float value)
{
    float newValue;

    newValue = value * (1 << this->_bits);
    this->_num = roundf(newValue);
    std::cout << "Float constructor called" << std::endl;
}

float Fixed::toFloat(void) const
{
    return (static_cast<float>(this->_num) / (1 << this->_bits));
}

int Fixed::toInt(void) const
{
    return (this->_num >> this->_bits);
}

Fixed& Fixed::operator=(const Fixed& other)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other)
        this->_num = other.getRawBits();
    return (*this);
}

int Fixed::getRawBits(void) const
{
    return (this->_num);
}

void Fixed::setRawBits(int const raw)
{
    this->_num = raw;
}

std::ostream& operator<<(std::ostream& output, const Fixed& data)
{
    output << data.toFloat();
    return (output);
}

bool Fixed::operator>(const Fixed &other) const
{
    return (this->_num > other._num);
}

bool Fixed::operator<(const Fixed &other) const
{
    return (this->_num < other._num);
}

bool Fixed::operator>=(const Fixed &other) const
{
    return (this->_num >= other._num);
}

bool Fixed::operator<=(const Fixed &other) const
{
    return (this->_num <= other._num);
}

bool Fixed::operator!=(const Fixed &other) const
{
    return (this->_num != other._num);
}

bool Fixed::operator==(const Fixed &other) const
{
    return (this->_num == other._num);
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
    this->_num = this->_num + 1;
    return (*this);
}

Fixed Fixed::operator++(int)
{
    Fixed aux;

    aux = *this;
    this->_num = this->_num + 1;
    return (aux);
}

Fixed& Fixed::operator--(void)
{
    this->_num = this->_num - 1;
    return (*this);
}

Fixed Fixed::operator--(int)
{
    Fixed aux;

    aux = *this;
    this->_num = this->_num - 1;
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
