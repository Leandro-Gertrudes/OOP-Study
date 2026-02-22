/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgertrud <lgertrud@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/11 16:56:48 by lgertrud          #+#    #+#             */
/*   Updated: 2026/01/12 15:27:17 by lgertrud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main() {
    ScavTrap s("Jack");

    std::cout << std::endl;
    s.attack("Enemy");
    s.takeDamage(30);
    s.beRepaired(20);
    s.guardGate();
    std::cout << std::endl;

    return 0;
}
