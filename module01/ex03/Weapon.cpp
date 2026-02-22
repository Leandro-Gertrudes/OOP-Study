/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgertrud <lgertrud@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 17:11:22 by lgertrud          #+#    #+#             */
/*   Updated: 2025/10/22 17:42:19 by lgertrud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string name)
{
	type = name;
}

std::string &Weapon::getType()
{
	std::string &getType = type;
	return(getType);
}

void Weapon::setType(std::string newType)
{
	this->type = newType;
}