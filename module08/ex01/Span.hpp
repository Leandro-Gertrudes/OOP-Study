/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgertrud <lgertrud@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/25 16:05:43 by lgertrud          #+#    #+#             */
/*   Updated: 2026/04/25 16:55:22 by lgertrud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP

#define SPAN_HPP

#include <iostream>
#include <string>
#include <sstream>
#include <stdexcept>
#include <math.h>

class Span{
	private:
		unsigned int N;
		int *array;
		int index;
	public:
		Span();
		Span(unsigned int Numb);
		Span(Span const &other);
		Span &operator=(Span const &other);
		~Span();

		void addNumber(int num);
		int shortestSpan();
		int longestSpan();
};





#endif