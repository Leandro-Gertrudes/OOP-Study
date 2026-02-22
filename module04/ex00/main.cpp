/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgertrud <lgertrud@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 17:18:12 by lgertrud          #+#    #+#             */
/*   Updated: 2026/01/17 16:05:55 by lgertrud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "animal.hpp"
#include "dog.hpp"
#include "cat.hpp"
#include "wrongAnimal.hpp"
#include "wrongCat.hpp"

int main() {
    const Animal* a = new Animal();
    const Animal* d = new Dog();
    const Animal* c = new Cat();
    
    std::cout << std::endl;
    std::cout << "get type d: " << d->getType() << std::endl;
    std::cout << "get type c: " << c->getType() << std::endl;
    std::cout << std::endl;

    std::cout << std::endl;
    std::cout << "---Sounds---" << std::endl;
    c->makeSound();
    d->makeSound();
    a->makeSound();
    std::cout << std::endl;

    std::cout << std::endl;
    delete a;
    delete d;
    delete c;
    std::cout << std::endl;
    std::cout << std::endl;

    std::cout << "---- WRONG ----" << std::endl;

    const WrongAnimal* wc = new WrongCat();
    std::cout << std::endl;
    std::cout << "get type wc: " << wc->getType() << std::endl;
    std::cout << std::endl;
    wc->makeSound();
    std::cout << std::endl;

    delete wc;
}
