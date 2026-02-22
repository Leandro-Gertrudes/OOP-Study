/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgertrud <lgertrud@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 14:57:06 by lgertrud          #+#    #+#             */
/*   Updated: 2025/10/27 13:12:50 by lgertrud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(std::string name)
{
	this->name = name;
}

void Zombie::announce( void )
{
	std::cout << name << ": BraiiiiiiinnnzzzZ... " << std::endl;
}

Zombie::~Zombie()
{
	std::cout << name << " has been destroyed." << std::endl;
}