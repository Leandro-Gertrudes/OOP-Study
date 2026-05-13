/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgertrud <lgertrud@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/08 20:52:08 by lgertrud          #+#    #+#             */
/*   Updated: 2026/05/13 16:59:44 by lgertrud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

#include "PmergeMe.hpp"
 
int main(int argc, char **argv){
 
	try{
		if(argc < 2)
			throw std::invalid_argument("Error");
 
		PmergeMe Exemple;
 
		Exemple.parseInput(argc, argv);
		Exemple.printBefore();
		Exemple.run();
		Exemple.printAfter();
		Exemple.printTimes();
	}
	catch(std::exception &e){
		std::cerr << e.what() << std::endl;
		return 1;
	}
 
	return 0;
}
 