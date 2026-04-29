/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgertrud <lgertrud@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/25 16:10:26 by lgertrud          #+#    #+#             */
/*   Updated: 2026/04/29 16:19:52 by lgertrud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span() : _N(0) {}

Span::Span(unsigned int N) : _N(N) {}

Span::Span(Span const &other) : _N(other._N), _vec(other._vec) {}

Span &Span::operator=(Span const &other) {
    if (this != &other) {
        _N = other._N;
        _vec = other._vec;
    }
    return *this;
}

Span::~Span() {}

void Span::addNumber(int num) {
    if (_vec.size() >= _N)
        throw std::length_error("Span is full");
    _vec.push_back(num);
}

int Span::shortestSpan() const {
    if (_vec.size() < 2)
        throw std::logic_error("Not enough numbers to find a span");

    std::vector<int> sorted(_vec);
    std::sort(sorted.begin(), sorted.end());

    int shortest = sorted[1] - sorted[0];
    for (size_t i = 2; i < sorted.size(); ++i) {
        int diff = sorted[i] - sorted[i - 1];
        if (diff < shortest)
            shortest = diff;
    }
    return shortest;
}

int Span::longestSpan() const {
    if (_vec.size() < 2)
        throw std::logic_error("Not enough numbers to find a span");

    return *std::max_element(_vec.begin(), _vec.end())
         - *std::min_element(_vec.begin(), _vec.end());
}