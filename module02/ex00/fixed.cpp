/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgertrud <lgertrud@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/04 14:44:43 by lgertrud          #+#    #+#             */
/*   Updated: 2026/01/06 12:04:00 by lgertrud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fixed.hpp"

/* default constructor */
Fixed::Fixed(){
    this->_rawBits = 0;
    std::cout << "Default constructor called" << std::endl;
}

/* copy constructor */
Fixed::Fixed(const Fixed& other) {
    std::cout << "Copy constructor called" << std::endl;
    *this = other;
}

/* assignment operator */
Fixed& Fixed::operator=(const Fixed& other) {
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other) {
        this->_rawBits = other.getRawBits();
    }
    return *this;
}

/* destructor */
Fixed::~Fixed() {
    std::cout << "Destructor called" << std::endl;
}

/* Getter */
int Fixed::getRawBits(void) const {
    std::cout << "getRawBits member function called" << std::endl;
    return this->_rawBits;
}

/* Setter */
void Fixed::setRawBits(int const raw) {
        std::cout << "setRawBits member function called" << std::endl;
    this->_rawBits = raw;
}
