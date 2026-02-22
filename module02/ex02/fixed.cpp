/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgertrud <lgertrud@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/04 16:45:37 by lgertrud          #+#    #+#             */
/*   Updated: 2026/01/06 13:53:40 by lgertrud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fixed.hpp"

/* OCF */
Fixed::Fixed() : _rawBits(0) {}
Fixed::Fixed(const Fixed& other) { *this = other; }
Fixed& Fixed::operator=(const Fixed& other) {
    if (this != &other)
        _rawBits = other._rawBits;
    return *this;
}
Fixed::~Fixed() {}

/* constructors */
Fixed::Fixed(const int value) {
    _rawBits = value << _fractionalBits;
}

Fixed::Fixed(const float value) {
    _rawBits = roundf(value * (1 << _fractionalBits));
}

/* convertors */
float Fixed::toFloat(void) const {
    return (float)_rawBits / (1 << _fractionalBits);
}

int Fixed::toInt(void) const {
    return _rawBits >> _fractionalBits;
}

/* comparators */
bool Fixed::operator>(const Fixed& other) const { return _rawBits > other._rawBits; }
bool Fixed::operator<(const Fixed& other) const { return _rawBits < other._rawBits; }
bool Fixed::operator>=(const Fixed& other) const { return _rawBits >= other._rawBits; }
bool Fixed::operator<=(const Fixed& other) const { return _rawBits <= other._rawBits; }
bool Fixed::operator==(const Fixed& other) const { return _rawBits == other._rawBits; }
bool Fixed::operator!=(const Fixed& other) const { return _rawBits != other._rawBits; }

/* math */
Fixed Fixed::operator+(const Fixed& other) const {
    Fixed result;
    result._rawBits = _rawBits + other._rawBits;
    return result;
}

Fixed Fixed::operator-(const Fixed& other) const {
    Fixed result;
    result._rawBits = _rawBits - other._rawBits;
    return result;
}

Fixed Fixed::operator*(const Fixed& other) const {
    Fixed result;
    long tmp = (long)_rawBits * (long)other._rawBits;
    result._rawBits = tmp >> _fractionalBits;
    return result;
}

Fixed Fixed::operator/(const Fixed& other) const {
    Fixed result;
    long tmp = ((long)_rawBits << _fractionalBits) / other._rawBits;
    result._rawBits = tmp;
    return result;
}

/* ++ / -- */
Fixed& Fixed::operator++() {
    _rawBits++;
    return *this;
}

Fixed Fixed::operator++(int) {
    Fixed tmp(*this);
    _rawBits++;
    return tmp;
}

Fixed& Fixed::operator--() {
    _rawBits--;
    return *this;
}

Fixed Fixed::operator--(int) {
    Fixed tmp(*this);
    _rawBits--;
    return tmp;
}

/* Min / Max */
Fixed& Fixed::min(Fixed& a, Fixed& b) {
    return (a < b) ? a : b;
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b) {
    return (a < b) ? a : b;
}

Fixed& Fixed::max(Fixed& a, Fixed& b) {
    return (a > b) ? a : b;
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b) {
    return (a > b) ? a : b;
}

/* Operator << */
std::ostream& operator<<(std::ostream& out, const Fixed& fixed) {
    out << fixed.toFloat();
    return out;
}
