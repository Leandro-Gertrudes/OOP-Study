/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00-main.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgertrud <lgertrud@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 12:13:29 by lgertrud          #+#    #+#             */
/*   Updated: 2025/09/25 13:50:53 by lgertrud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "h-phonebook.hpp"

int main(void)
{
	PhoneBook pb;
	std::string cmd;

	do
	{
		cmd = "";
		std::cout << MENU << std::endl;
		while(cmd != "SEARCH" && cmd != "ADD" && cmd != "EXIT")
		{
			std::cout << "> ";
			std::getline(std::cin, cmd);
		}
		if(cmd == "ADD")
			pb.addContact();
		if(cmd == "SEARCH")
			pb.searchContacts();
	} while(cmd != "EXIT");
	return (0);
}
PhoneBook::PhoneBook() : count(0) {

}
