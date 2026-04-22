/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgertrud <lgertrud@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 16:33:22 by lgertrud          #+#    #+#             */
/*   Updated: 2026/04/22 16:48:22 by lgertrud         ###   ########.fr       */
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
T min(T a, T b){
	if(b <= a)
		return (b);
	else
		return a;
}

template <typename T>
T max(T a, T b){
	if(b >= a)
		return (b);
	else
		return a;
}

#endif