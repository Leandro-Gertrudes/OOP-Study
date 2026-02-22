/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   h-phonebook.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgertrud <lgertrud@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 12:50:52 by lgertrud          #+#    #+#             */
/*   Updated: 2025/09/29 11:45:23 by lgertrud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP


#include <iostream>
#include <sstream>
#include <iomanip>
#include <string>
#include "h-contact.hpp"
#include "h-defines.hpp"

class PhoneBook {
private:
    Contact contacts[8];
    int count;

	std::string getInput(const std::string &prompt);
public:
    PhoneBook();
    void addContact();
   	void searchContacts();
};

#endif
