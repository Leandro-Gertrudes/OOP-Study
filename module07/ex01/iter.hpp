/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgertrud <lgertrud@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/23 14:26:17 by lgertrud          #+#    #+#             */
/*   Updated: 2026/04/23 16:20:47 by lgertrud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP

#define ITER_HPP

#include <iostream>
#include <string>


template <typename T, typename F>
void iter(T *array, size_t const length, F f) {
    for (size_t i = 0; i < length; i++)
        f(array[i]);
}

template <typename T, typename F>
void iter(T const *array, size_t const length, F f) {
    for (size_t i = 0; i < length; i++)
        f(array[i]);
}

#endif