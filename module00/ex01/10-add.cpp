/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   10-add.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgertrud <lgertrud@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 13:23:39 by lgertrud          #+#    #+#             */
/*   Updated: 2025/09/25 13:52:47 by lgertrud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "h-phonebook.hpp"

bool onlySpaces(const std::string& input);

void PhoneBook::addContact() {

	static int index;

    std::cout << ADD << std::endl;

    std::string firstName = getInput("\033[1;36m>> First name: \033[0m");
    std::string lastName  = getInput("\033[1;36m>> Last name: \033[0m");
    std::string nickname  = getInput("\033[1;36m>> Nickname: \033[0m");
    std::string phone     = getInput("\033[1;36m>> Phone number: \033[0m");
    std::string secret    = getInput("\033[1;36m>> Darkest secret: \033[0m");

	contacts[index].setInfo(firstName, lastName, nickname, phone, secret);

	index++;
	if(index == 8)
		index = 0;
	if(count < 8)
		count++;

    std::cout << MSG_SUCCESS << std::endl;
}

std::string PhoneBook::getInput(const std::string &prompt) {
    std::string input;
	
    do {
        std::cout << prompt;
        std::getline(std::cin, input);
        if (input.empty() || onlySpaces(input))
            std::cout << MSG_REQUIRED << std::endl;
    } while (input.empty() || onlySpaces(input));

    return input;
}

bool onlySpaces(const std::string& input)
{
	bool onlySpaces = true;

	for (int i = 0; input[i]; i++) {
		if (!std::isspace(input[i])) {
			onlySpaces = false;
			break;
		}
	}
	return onlySpaces;
}
