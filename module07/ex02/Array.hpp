/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgertrud <lgertrud@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/23 15:22:30 by lgertrud          #+#    #+#             */
/*   Updated: 2026/04/23 16:09:28 by lgertrud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <cstdlib>
#include <ctime> 
#include <iostream>
#include <stdexcept>

template<typename T>
class Array {
private:
    T*           data;
    unsigned int _size;

public:
    Array();
    Array(unsigned int n);
    Array(const Array &other);
    Array& operator=(const Array &other);
    ~Array();

    T&     operator[](unsigned int index);
    const T& operator[](unsigned int index) const;

    unsigned int size() const;
};

#include "Array.tpp"

#endif
