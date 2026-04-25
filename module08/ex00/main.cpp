/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgertrud <lgertrud@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/23 16:50:21 by lgertrud          #+#    #+#             */
/*   Updated: 2026/04/23 17:01:29 by lgertrud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

int main(){
	std::vector<int> test;
	test.push_back(10);
    test.push_back(20);
    test.push_back(42);
    test.push_back(99);

	try{
		easyfinder(test, 42);
		std::cout << "found value" << std::endl;
	}
	catch(std::exception &e){
		std::cerr << e.what();
	}

	try{
		easyfinder(test, 65);
		std::vector<int>::iterator it = easyfinder(test, 42);
		std::cout << "found: " << *it << std::endl;
	}
	catch(std::exception &e){
		std::cerr << e.what() << std::endl;
	}
}