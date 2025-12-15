/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlopez <carlopez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 19:31:31 by carlopez          #+#    #+#             */
/*   Updated: 2025/12/15 17:00:38 by carlopez         ###   ########.fr       */
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

Fixed& Fixed::operator=(const Fixed& other)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other)
        this->_num = other.getRawBits();
    return (*this);
}

Fixed::Fixed(const Fixed& other)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = other;
}

Fixed::Fixed(const int value) : _num(value << this->bits)
{
    std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float value)
{
    float newValue;
    
    newValue = value * (1 << this->bits);
    this->_num = roundf(newValue);
    std::cout << "Float constructor called" << std::endl;
}

float Fixed::toFloat(void) const
{
    return (static_cast<float>(this->_num) / (1 << this->bits));
}

int Fixed::toInt(void) const
{
    return (this->_num >> this->bits);
}

int Fixed::getRawBits(void) const
{
    std::cout << "getRawBits member function called" << std::endl;
    return (this->_num);
}

void Fixed::setRawBits(int const raw)
{
    std::cout << "setRawBits member function called" << std::endl;
    this->_num = raw;
}

std::ostream& operator<<(std::ostream& output, const Fixed& data)
{
    output << data.toFloat();
    return (output);
}