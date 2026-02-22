/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgertrud <lgertrud@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 17:15:33 by lgertrud          #+#    #+#             */
/*   Updated: 2026/01/12 14:21:22 by lgertrud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main (void)
{
	ClapTrap duck("Duck");

	std::cout << std::endl;
	
	duck.attack("Eagle");
	
	duck.takeDamage(7);
	
	duck.beRepaired(7);
	
	std::cout << std::endl;
	return (0);
}