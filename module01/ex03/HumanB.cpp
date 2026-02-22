/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgertrud <lgertrud@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 11:50:04 by lgertrud          #+#    #+#             */
/*   Updated: 2025/10/23 12:11:06 by lgertrud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string newName)
{
	name = newName;
	arms = NULL;
}

void	HumanB::setWeapon(Weapon &wea)
{
	arms = &wea;
}
void HumanB::attack() {
	if (arms)
	{
		std::cout << name;
		std::cout <<" attacks with their ";
		std::cout << arms->getType() << std::endl;
	}
	else
	{
		std::cout << name;
		std::cout << " cannot attack" << std::endl;
	}
}
