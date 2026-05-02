/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgertrud <lgertrud@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/23 16:50:21 by lgertrud          #+#    #+#             */
/*   Updated: 2026/05/02 14:00:25 by lgertrud         ###   ########.fr       */
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
		std::vector<int>::iterator it = easyfind(test, 42);
		std::cout << "found value: " << *it << std::endl;
	}
	catch(std::exception &e){
		std::cerr << e.what();
	}

	try{
		std::vector<int>::iterator it = easyfind(test, 65);
		std::cout << "found: " << *it << std::endl;
	}
	catch(std::exception &e){
		std::cerr << e.what() << std::endl;
	}
}