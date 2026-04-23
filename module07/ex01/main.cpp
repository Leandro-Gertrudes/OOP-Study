/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgertrud <lgertrud@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 16:32:17 by lgertrud          #+#    #+#             */
/*   Updated: 2026/04/23 15:08:37 by lgertrud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

void toUpper(char &c) {
    if (c >= 'a' && c <= 'z')
        c -= 32;
}

void printUpper(const char &c) {
    char tmp = c;

    if (tmp >= 'a' && tmp <= 'z')
        tmp -= 32;

    std::cout << tmp;
}

int main(void) {

	//mutable
    std::string str = "\"mutable...\"";
    size_t length = str.size();

    std::cout << "Original string: " << str << std::endl;
    iter(&str[0], length, toUpper);

    std::cout << "After toUpper (modified): " << str << std::endl;
	std::cout << std::endl;




	
	//const
    const std::string strConst = "\"immutable..\"";

    std::cout << "Const string printed uppercase: ";

    iter(strConst.c_str(), strConst.size(), printUpper);
	std::cout << std::endl;

	std::cout << "After printUpper: " << strConst;

    std::cout << std::endl;

    return 0;
}