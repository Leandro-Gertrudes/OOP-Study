/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgertrud <lgertrud@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 12:06:45 by lgertrud          #+#    #+#             */
/*   Updated: 2026/01/12 15:48:03 by lgertrud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

/* OCF */
ClapTrap::ClapTrap() : name("default"), hitPoints(10),
						energyPoints(10), attackDamage(0)
{
	std::cout << "ClapTrap default created." << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &other) {
	*this = other;
	std::cout << "copy constructor called." << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if(this != &other)
	{
		name = other.name;
		hitPoints	 = other.hitPoints;
		energyPoints = other.energyPoints;
		attackDamage = other.attackDamage;
	}
	return *this;
}

ClapTrap::~ClapTrap(){
	std::cout << BOLD << name << UNBOLD << " destroyed." << std::endl;
}


//constructor with Name//
ClapTrap::ClapTrap(const std::string& _name): name(_name), hitPoints(10),
											energyPoints(10), attackDamage(0)
{
	std::cout << "ClapTrap: " << BOLD << name << UNBOLD <<" created." << std::endl;
}

void ClapTrap::attack(const std::string &target)
{
	if(hitPoints == 0)
	{
		std::cout << YELLOW << "ClapTrap " << BOLD << name << UNBOLD << " is dead, he cannot attack" << RESET << std::endl;
		return ;
	}
	else if(energyPoints == 0)
	{
		std::cout << YELLOW << "ClapTrap " << BOLD << name << UNBOLD << " cannot attack because he dont have energy points." << RESET << std::endl;
		return ;
	}

	energyPoints--;
	std::cout << RED BOLD << "ClapTrap " << name << " attacks " << target;
	std::cout << " causing " << attackDamage << " points of damage!" << RESET << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if(hitPoints == 0)
	{
		std::cout << MAGENTA << "ClapTrap " << BOLD << name << UNBOLD << " is already dead, why do u keep hitting him? " << RESET <<std::endl;
		return ;
	}
	if (amount >= hitPoints)
		hitPoints = 0;
	else
		hitPoints -= amount;

	std::cout << ORANGE << "ClapTrap " << BOLD << name << UNBOLD << " took " << amount << " damage, ";
	if(hitPoints)
		std::cout << "ending up with only "<< hitPoints <<" hit points" << std::endl;
	else
		std::cout << "he is "<< RED BOLD << "DEAD." << std::endl;
	std::cout << RESET;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if(hitPoints == 0)
	{
		std::cout << YELLOW << "!!ClapTrap " << BOLD << name << UNBOLD << " is dead, he cant be repaired." << RESET << std::endl;
		return ;
	}
	else if(energyPoints == 0)
	{
		std::cout << YELLOW << "!!ClapTrap " << BOLD << name << UNBOLD << " cant be repaired why he dont have energy points." << RESET << std::endl;
		return ;
	}

	hitPoints += amount;
	energyPoints--;
	std::cout << GREEN << "ClapTrap " << BOLD << name << UNBOLD << " repaired " << amount;
	std::cout << " hit points." << " now he was "<< hitPoints << " hit points." << RESET << std::endl;
}
