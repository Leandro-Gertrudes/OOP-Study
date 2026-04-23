/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgertrud <lgertrud@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/23 14:26:17 by lgertrud          #+#    #+#             */
/*   Updated: 2026/04/23 14:53:48 by lgertrud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP

#define ITER_HPP

#include <iostream>
#include <string>


template <typename T, typename L, typename F>
void iter(T *array, L const lenght, F f){
	for(L i = 0; i < lenght; i++)
		f(array[i]);
}

template <typename T, typename L, typename F>
void iter(T const *array, L const lenght, F f){
	for(L i = 0; i < lenght; i++)
		f(array[i]);
}

#endif