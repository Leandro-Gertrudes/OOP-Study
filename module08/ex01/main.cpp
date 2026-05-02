/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgertrud <lgertrud@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/23 16:50:21 by lgertrud          #+#    #+#             */
/*   Updated: 2026/05/02 14:35:11 by lgertrud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

static void testLarge() {
    std::cout << "\n--- Test with 10000 numbers ---" << std::endl;
	std::srand(std::time(0));

    Span sp(10000);
    std::vector<int> v;
    for (int i = 0; i < 10000; ++i)
        v.push_back(std::rand());
    sp.addRange(v.begin(), v.end());

    std::cout << "Shortest: " << sp.shortestSpan() << std::endl;
    std::cout << "Longest:  " << sp.longestSpan()  << std::endl;
}

int main()
{
	try{
		Span sp = Span(5);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;

		testLarge();
		return 0;
	}
	catch(std::exception &e){
		std::cerr << e.what() << std::endl;
	}
}