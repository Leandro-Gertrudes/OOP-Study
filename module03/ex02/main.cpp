/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgertrud <lgertrud@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/11 17:07:49 by lgertrud          #+#    #+#             */
/*   Updated: 2026/01/12 16:38:32 by lgertrud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

int main() {
    FragTrap f("Freddie");

    std::cout << std::endl;
    f.attack("Enemy");
    f.takeDamage(40);
    f.beRepaired(20);
    f.highFivesGuys();
    std::cout << std::endl;

    return 0;
}
