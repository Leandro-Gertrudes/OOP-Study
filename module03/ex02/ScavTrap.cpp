/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgertrud <lgertrud@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/11 16:53:26 by lgertrud          #+#    #+#             */
/*   Updated: 2026/01/12 16:32:18 by lgertrud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

/* Constructors */
ScavTrap::ScavTrap() : ClapTrap("ScavTrap") {
    hitPoints = 100;
    energyPoints = 50;
    attackDamage = 20;
    std::cout << "ScavTrap default constructor called" << std::endl;
}

ScavTrap::ScavTrap(const std::string& name) : ClapTrap(name) {
    hitPoints = 100;
    energyPoints = 50;
    attackDamage = 20;
    std::cout << "ScavTrap constructor called for " << name << std::endl;
}

/* Copy constructor */
ScavTrap::ScavTrap(const ScavTrap& other) : ClapTrap(other) {
    std::cout << "ScavTrap copy constructor called" << std::endl;
}

/* Copy assignment */
ScavTrap& ScavTrap::operator=(const ScavTrap& other) {
    if (this != &other) {
        ClapTrap::operator=(other);
    }
    std::cout << "ScavTrap copy assignment operator called" << std::endl;
    return *this;
}

/* Destructor */
ScavTrap::~ScavTrap() {
    std::cout << "ScavTrap destructor called for " << name << std::endl;
}

/* Methods */
void ScavTrap::attack(const std::string& target) {
    if (hitPoints <= 0 || energyPoints <= 0) {
        std::cout << "ScavTrap " << name << " can't attack!" << std::endl;
        return;
    }

    energyPoints--;
    std::cout << RED << "ScavTrap " << BOLD << name << UNBOLD
              << " hit " << BOLD << target << UNBOLD
              << " with " << attackDamage
              << " points of damage!" << RESET << std::endl;
}

void ScavTrap::guardGate() {
    if (hitPoints <= 0 || energyPoints <= 0)
    {
        std::cout << YELLOW  << "ScavTrap " << BOLD << name << UNBOLD << " can't do anything." << RESET << std::endl;
        return ;
    }
        
    energyPoints--;
    std::cout << BLUE << "ScavTrap " << BOLD << name << UNBOLD << " is now in Gate keeper mode." << RESET << std::endl;
}
