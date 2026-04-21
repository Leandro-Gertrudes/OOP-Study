/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgertrud <lgertrud@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/16 15:09:19 by lgertrud          #+#    #+#             */
/*   Updated: 2026/04/21 16:34:08 by lgertrud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

Base* generate(void);
void identify(Base* p);
void identify(Base& p);

int main()
{
    
    Base* obj = generate();

    std::cout << "Pointer identify: ";
    identify(obj);

    std::cout << "Reference identify: ";
    identify(*obj);

    delete obj;
    return 0;
}
