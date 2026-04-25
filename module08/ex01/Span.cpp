/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgertrud <lgertrud@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/25 16:10:26 by lgertrud          #+#    #+#             */
/*   Updated: 2026/04/25 17:41:30 by lgertrud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

//canonical

Span::Span(){
	this->N = 0;
	this->index = -1;
}

Span::Span(unsigned int Numb){
	this->N = Numb;
	this->array = new int[N];
	this->index = 0;
}

Span::Span(Span const &other){
	*this = other;
}

Span &Span::operator=(Span const &other){
	if(this != &other){
		this->N = other.N;
		this->array = other.array;
		this->index = other.index;
	}
	return *this;
}

Span::~Span(){
	delete this->array;
}

// functions


void Span::addNumber(int num){
	if((unsigned int)this->index > this->N - 1)
		throw std::out_of_range("Error");

	array[index] = num;
	index++;
}

int Span::shortestSpan(){
	if(index == 0)
		throw std::logic_error("Error");

	int i = 0;
	int j = 0;
	int tmp = 0;
	int shortest = 0;

	while(i <= this->index){
		j = 0;
		while(j <= this->index){
			if(j != i)
				tmp = abs(this->array[j] - this->array[i]);
			if (shortest == 0 || tmp < shortest){
				shortest = tmp;
			}
			j++;
		}
		i++;
	}
	return shortest;
}

int nMin(int *arr, int size) {
    if (size < 0)
        throw std::logic_error("empty Array");

    int min = arr[0];

    for (int i = 1; i < size; i++) {
        if (arr[i] < min)
            min = arr[i];
    }

    return min;
}

int nMax(int *arr, int size) {
    if (size < 0)
        throw std::logic_error("empty Array");

    int max = arr[0];

    for (int i = 1; i < size; i++) {
        if (arr[i] > max)
            max = arr[i];
    }

    return max;
}


int Span::longestSpan(){
	if(index == 0)
		throw std::logic_error("Error");

	int min = nMin(this->array, this->index);
	int max = nMax(this->array, this->index);


	return abs(max - min);
}

