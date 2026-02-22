/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgertrud <lgertrud@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/11 17:07:10 by lgertrud          #+#    #+#             */
/*   Updated: 2026/01/12 16:05:07 by lgertrud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include <iostream>

/* Constructors */
FragTrap::FragTrap() : ClapTrap("FragTrap") {
    hitPoints = 100;
    energyPoints = 100;
    attackDamage = 30;
    std::cout << "FragTrap default constructor called" << std::endl;
}

FragTrap::FragTrap(const std::string& name) : ClapTrap(name) {
    hitPoints = 100;
    energyPoints = 100;
    attackDamage = 30;
    std::cout << "FragTrap constructor called for " << name << std::endl;
}

/* Copy constructor */
FragTrap::FragTrap(const FragTrap& other) : ClapTrap(other) {
    std::cout << "FragTrap copy constructor called" << std::endl;
}

/* Copy assignment */
FragTrap& FragTrap::operator=(const FragTrap& other) {
    if (this != &other) {
        ClapTrap::operator=(other);
    }
    std::cout << "FragTrap copy assignment operator called" << std::endl;
    return *this;
}

/* Destructor */
FragTrap::~FragTrap() {
    std::cout << "FragTrap destructor called for " << name << std::endl;
}

/* Special ability */
void FragTrap::highFivesGuys(void) {
    if (hitPoints <= 0 || energyPoints <= 0) {
        std::cout << YELLOW << "FragTrap " << name << " can't do anything!" << RESET << std::endl;
        return;
    }

    std::cout << TURQUOISE << "FragTrap " << BOLD << name << UNBOLD
              << " requests a positive high five! ✋" << RESET << std::endl;
}
