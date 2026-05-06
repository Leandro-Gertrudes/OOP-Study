/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgertrud <lgertrud@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/05 16:28:41 by lgertrud          #+#    #+#             */
/*   Updated: 2026/05/06 15:16:09 by lgertrud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main(int argc, char **argv){
	
	try{
		if(argc !=2 )
			throw std::invalid_argument("invalid input");
	
		int result = RPN(argv[1]);
	
		std::cout << result << std::endl;
	}
	catch(std::exception &e){
		std::cerr << e.what() << std::endl;
	}
	
}