/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   20-search.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgertrud <lgertrud@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 13:42:46 by lgertrud          #+#    #+#             */
/*   Updated: 2025/09/29 11:35:02 by lgertrud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "h-phonebook.hpp"

static int	get_index(int count);

bool onlySpaces(const std::string& input);

void PhoneBook::searchContacts()
{
	int index;

	std::cout << SEARCH <<
			  "   Index  " << "|"
			  << "First Name" << "|"
			  << "Last Name " << "|"
			  << " Nickname " << std::endl;
	for(int i = 0; i < count; i++)
		contacts[i].displaySearch(i + 1);
	std::cout << std::endl;
	
	if(count > 0){
		index = get_index(count);
		contacts[index - 1].displayIndex();
	}

	std::cout << std::endl;
}

static int get_index(int count)
{
    std::string input;
    int index;

    while (1)
    {
        std::cout << "Enter index: ";
        std::getline(std::cin, input);

        std::stringstream ss(input);

        if (!(ss >> index) || !(ss.eof())){
            std::cout << SYMBOL_ERROR <<  " Please enter a number!\n";
            continue;
        }

        if (index < 1 || index > count) {
            std::cout << SYMBOL_ERROR <<  " Contact not found. Please choose an index between 1 and " << count << ".\n";
            continue;
        }

        break;
    }
	return index;
}