/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgertrud <lgertrud@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 17:14:22 by lgertrud          #+#    #+#             */
/*   Updated: 2025/10/23 11:48:07 by lgertrud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string newName, Weapon &wea)
	: name(newName), arms(wea)
{
}

void HumanA::attack() {
	std::cout << name << " attacks with their " << arms.getType() << std::endl;
}