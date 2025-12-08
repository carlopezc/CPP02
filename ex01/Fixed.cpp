/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlopez <carlopez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 19:31:31 by carlopez          #+#    #+#             */
/*   Updated: 2025/12/08 19:54:14 by carlopez         ###   ########.fr       */
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

float Fixed::toFloat(void)
{
    return (this->num >> this->bits);
}

float Fixed::toInt(void)
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