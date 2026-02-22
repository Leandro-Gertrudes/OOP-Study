/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgertrud <lgertrud@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/04 16:09:37 by lgertrud          #+#    #+#             */
/*   Updated: 2026/01/07 14:44:24 by lgertrud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fixed.hpp"

/* Default constructor */
Fixed::Fixed() {
    this->_rawBits = 0;
    std::cout << "Default constructor called" << std::endl;
}

/* Int constructor */
Fixed::Fixed(const int value) {
    std::cout << "Int constructor called" << std::endl;
    _rawBits = value << _fractionalBits;
}

/* Float constructor */
Fixed::Fixed(const float value) {
    std::cout << "Float constructor called" << std::endl;
    _rawBits = roundf(value * (1 << _fractionalBits));
}

/* Copy constructor */
Fixed::Fixed(const Fixed& other) {
    std::cout << "Copy constructor called" << std::endl;
    *this = other;
}

/* assignment operator */
Fixed& Fixed::operator=(const Fixed& other) {
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other)
        _rawBits = other.getRawBits();
    return *this;
}

/* Destructor called */
Fixed::~Fixed() {
    std::cout << "Destructor called" << std::endl;
}

/* Getter */
int Fixed::getRawBits(void) const {
    return _rawBits;
}

/* Setter */
void Fixed::setRawBits(int const raw) {
    _rawBits = raw;
}

float Fixed::toFloat(void) const {
    return (float)_rawBits / (1 << _fractionalBits);
}

int Fixed::toInt(void) const {
    return _rawBits >> _fractionalBits;
}

std::ostream& operator<<(std::ostream& out, const Fixed& fixed) {
    out << fixed.toFloat();
    return out;
}
