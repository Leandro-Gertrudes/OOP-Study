/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgertrud <lgertrud@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/04 16:22:49 by lgertrud          #+#    #+#             */
/*   Updated: 2026/01/07 15:27:50 by lgertrud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fixed.hpp"

int test(void);

int main( void ) {
    //return (test());
    Fixed a;
    Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
    
    std::cout << a << std::endl;
    std::cout << ++a << std::endl;
    std::cout << a << std::endl;
    std::cout << a++ << std::endl;
    std::cout << a << std::endl;
    
    std::cout << b << std::endl;
    
    std::cout << Fixed::max( a, b ) << std::endl;
    
    return 0;
}


int test(void) {

    std::cout << "=== constructors ===" << std::endl;
    Fixed a;                    // default
    Fixed b(10);                // int
    Fixed c(42.5f);            // float
    Fixed d(b);                 // copy

    std::cout << "a = " << a << std::endl;
    std::cout << "b = " << b << std::endl;
    std::cout << "c = " << c << std::endl;
    std::cout << "d = " << d << std::endl;

    std::cout << "\n=== << ===" << std::endl;
    a = Fixed(5.5f);
    std::cout << "a = " << a << std::endl;

    std::cout << "\n=== comparator ===" << std::endl;
    std::cout << "b = " << b << std::endl;
    std::cout << "c = " << c << std::endl;
    std::cout << "\nb > c  = " << (b > c) << std::endl;
    std::cout << "b < c  = " << (b < c) << std::endl;
    std::cout << "b >= c = " << (b >= c) << std::endl;
    std::cout << "b <= c = " << (b <= c) << std::endl;
    std::cout << "b == c = " << (b == c) << std::endl;
    std::cout << "b != c = " << (b != c) << std::endl;

    std::cout << "\n=== math ===" << std::endl;
    std::cout << "b + c = " << (b + c) << std::endl;
    std::cout << "c - b = " << (c - b) << std::endl;
    std::cout << "b * c = " << (b * c) << std::endl;
    std::cout << "c / b = " << (c / b) << std::endl;

    std::cout << "\n=== ++ / -- ===" << std::endl;
    Fixed e(42);

    std::cout << "e     = " << e << std::endl;
    std::cout << "++e   = " << ++e << std::endl;
    std::cout << "e     = " << e << std::endl;
    std::cout << "e++   = " << e++ << std::endl;
    std::cout << "e     = " << e << std::endl;

    std::cout << "--e   = " << --e << std::endl;
    std::cout << "e--   = " << e-- << std::endl;
    std::cout << "e     = " << e << std::endl;

    std::cout << "\n=== MIN / MAX ===" << std::endl;
    Fixed f(1.25f);
    Fixed g(2.75f);

    std::cout << "min(f, g) = " << Fixed::min(f, g) << std::endl;
    std::cout << "max(f, g) = " << Fixed::max(f, g) << std::endl;

    const Fixed h(3.5f);
    const Fixed i(4.5f);

    std::cout << "min(h, i) = " << Fixed::min(h, i) << std::endl;
    std::cout << "max(h, i) = " << Fixed::max(h, i) << std::endl;

    return 0;
}
