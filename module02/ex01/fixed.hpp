/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgertrud <lgertrud@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/04 16:08:29 by lgertrud          #+#    #+#             */
/*   Updated: 2026/01/06 13:08:15 by lgertrud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed {
private:
    int _rawBits;
    static const int _fractionalBits = 8;

public:
    Fixed();
    Fixed(const Fixed& other);
    Fixed &operator=(const Fixed& other);
    ~Fixed();
    Fixed(const int value);
    Fixed(const float value);

    float toFloat(void) const;
    int   toInt(void) const;
    int  getRawBits(void) const;
    void setRawBits(int const raw);
};

std::ostream &operator<<(std::ostream& out, const Fixed& fixed);

#endif
