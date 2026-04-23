/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgertrud <lgertrud@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 16:33:22 by lgertrud          #+#    #+#             */
/*   Updated: 2026/04/23 14:23:56 by lgertrud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP

#define WHATEVER_HPP

#include <iostream>

template <typename T>
void swap(T &a, T &b){
	T temp;
	temp = a;
	a = b;
	b = temp;
}

template <typename T>
T const &min(T const &a, T const &b){
	if(b <= a)
		return (b);
	else
		return a;
}

template <typename T>
T const &max(T const &a, T const &b){
	if(b >= a)
		return (b);
	else
		return a;
}

#endif