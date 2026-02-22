/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgertrud <lgertrud@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/11 17:35:23 by lgertrud          #+#    #+#             */
/*   Updated: 2026/01/12 16:31:34 by lgertrud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

/* Constructors */
DiamondTrap::DiamondTrap()
    : ClapTrap("DiamondTrap_clap_name"),
      FragTrap(),
      ScavTrap(),
      name("DiamondTrap") {

    hitPoints = FragTrap::hitPoints;
    energyPoints = ScavTrap::energyPoints;
    attackDamage = FragTrap::attackDamage;

    std::cout << "DiamondTrap default constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(const std::string& name)
    : ClapTrap(name + "_clap_name"),
      FragTrap(name),
      ScavTrap(name),
      name(name) {

    hitPoints = FragTrap::hitPoints;
    energyPoints = ScavTrap::energyPoints;
    attackDamage = FragTrap::attackDamage;

    std::cout << "DiamondTrap constructor called for " << name << std::endl;
}

/* Copy constructor */
DiamondTrap::DiamondTrap(const DiamondTrap& other)
    : ClapTrap(other),
      FragTrap(other),
      ScavTrap(other),
      name(other.name) {

    std::cout << "DiamondTrap copy constructor called" << std::endl;
}

/* Copy assignment */
DiamondTrap& DiamondTrap::operator=(const DiamondTrap& other) {
    if (this != &other) {
        ClapTrap::operator=(other);
        name = other.name;
    }
    std::cout << "DiamondTrap copy assignment operator called" << std::endl;
    return *this;
}

/* Destructor */
DiamondTrap::~DiamondTrap() {
    std::cout << "DiamondTrap destructor called for " << name << std::endl;
}

void DiamondTrap::whoAmI() {
    std::cout << OCEAN_DARK << "DiamondTrap name: " << name << std::endl;
    std::cout << "ClapTrap name: " << ClapTrap::name << RESET <<  std::endl;
}
