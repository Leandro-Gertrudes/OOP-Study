/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgertrud <lgertrud@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/11 17:07:49 by lgertrud          #+#    #+#             */
/*   Updated: 2026/01/12 16:35:41 by lgertrud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int main() {
    DiamondTrap d("Zed");

    std::cout << std::endl;
    d.attack("Enemy");
    d.takeDamage(20);
    d.beRepaired(10);
    d.highFivesGuys();
    d.guardGate();
    d.whoAmI();

    std::cout << std::endl;
    return 0;
}
