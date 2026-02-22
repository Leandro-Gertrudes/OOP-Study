/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgertrud <lgertrud@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/04 16:48:26 by lgertrud          #+#    #+#             */
/*   Updated: 2026/01/06 14:32:31 by lgertrud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "point.hpp"

int main(void) {
    Point a(0, 0);
    Point b(10, 0);
    Point c(10, 10);

    Point inside(5, 2);
    Point outside(12, 5);

    std::cout << bsp(a, b, c, inside) << std::endl;
    std::cout << bsp(a, b, c, outside) << std::endl;

    //Point test( , );
   // std::cout << bsp(a, b, c, test) << std::endl;
}
