/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   h-contact.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgertrud <lgertrud@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 12:50:29 by lgertrud          #+#    #+#             */
/*   Updated: 2025/09/25 14:39:13 by lgertrud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>


class Contact {
private:
    std::string firstName;
    std::string lastName;
    std::string nickname;
    std::string phoneNumber;
    std::string darkestSecret;

public:
    void setInfo(std::string fName, std::string lName, std::string nname,
			std::string pn, std::string scrt)
	{
		firstName     = fName;
		lastName      = lName;
		nickname      = nname;
		phoneNumber   = pn;
		darkestSecret = scrt;
	}
	
	std::string nameFormated(const std::string &str)
	{
		if (str.length() > 10)
			return str.substr(0, 9) + ".";
		return str;
	}

	void displaySearch(int index)
	{
		std::cout << std::left
				<< std::setw(10) << index << "|"
				<< std::setw(10) << nameFormated(firstName) << "|"
				<< std::setw(10) << nameFormated(lastName) << "|"
				<< std::setw(10) << nameFormated(nickname) << std::endl;
	}

    void displayIndex()
	{
	std::cout << "\n\033[1;36m>>> CONTACT FOUND <<<\033[0m\n\n";

    std::cout << "• First name     : " << firstName << std::endl;
    std::cout << "• Last name      : " << lastName << std::endl;
    std::cout << "• Nickname       : " << nickname << std::endl;
    std::cout << "• Phone number   : " << phoneNumber << std::endl;
    std::cout << "• Darkest secret : " << darkestSecret << std::endl;
    }
};

#endif