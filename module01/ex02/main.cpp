/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgertrud <lgertrud@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 14:10:08 by lgertrud          #+#    #+#             */
/*   Updated: 2025/10/22 17:51:18 by lgertrud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main()
{
	std::string str = "HI THIS IS BRAIN";
	std::string *stringPTR = &str;
	std::string &stringREF = str;

    std::cout << "\n------/Memory Addresses\n" << std::endl;

	std:: cout << "The memory address of the string variable: " << &str << std::endl;
	std:: cout << "The memory address held by stringPTR: " << &stringPTR << std::endl;
	std:: cout << "The memory address held by stringREF: " << &stringREF << std::endl;

    std::cout << "\n------/Values\n" << std::endl;

	std:: cout << "The memory address of the string variable: " << str << std::endl;
	std:: cout << "The memory address held by stringPTR: " << stringPTR << std::endl;
	std:: cout << "The memory address held by stringREF: " << stringREF << std::endl;
}
