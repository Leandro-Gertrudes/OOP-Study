/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgertrud <lgertrud@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/07 14:35:57 by lgertrud          #+#    #+#             */
/*   Updated: 2026/05/22 16:02:23 by lgertrud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int argc, char **argv){
	if(argc != 2){
		std::cout << "Error, input incorrect, usage: btc <filename>" << std::endl;
		return 1;
	}

	try{

		BitcoinExchange Exemple;
	
		Exemple.processExchange(argv[1]);
		
	}
	catch(std::exception &e){
		std::cerr << e.what() << std::endl;
	}
}
