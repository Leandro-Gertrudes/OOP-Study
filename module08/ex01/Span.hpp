/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgertrud <lgertrud@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/25 16:05:43 by lgertrud          #+#    #+#             */
/*   Updated: 2026/04/29 16:20:11 by lgertrud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP

#define SPAN_HPP

#include <iostream>
#include <string>
#include <sstream>
#include <stdexcept>
#include <algorithm>
#include <vector>
#include <math.h>

class Span {
    private:
        unsigned int    _N;
        std::vector<int> _vec;

    public:
        Span();
        Span(unsigned int N);
        Span(Span const &other);
        Span &operator=(Span const &other);
        ~Span();

        void addNumber(int num);

        template<typename Iterator>
        void addRange(Iterator begin, Iterator end) {
            if (_vec.size() + std::distance(begin, end) > _N)
                throw std::length_error("Span is full");
            _vec.insert(_vec.end(), begin, end);
        }

        int shortestSpan() const;
        int longestSpan() const;
};





#endif