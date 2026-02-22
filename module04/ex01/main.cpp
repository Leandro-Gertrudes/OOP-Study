/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgertrud <lgertrud@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 17:18:12 by lgertrud          #+#    #+#             */
/*   Updated: 2026/01/17 16:40:41 by lgertrud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "animal.hpp"
#include "dog.hpp"
#include "cat.hpp"

int main() {

    const Animal* animals[4];

    for (int i = 0; i < 2; i++)
        animals[i] = new Dog();
    for (int i = 2; i < 4; i++)
        animals[i] = new Cat();

    std::cout << "\n--- DEEP COPY TEST ---\n" << std::endl;

    Dog* original = new Dog();
    std::cout << std::endl;
    original->getBrain()->setIdea(0, "I want food");

    Dog *copy = new Dog(*original);
    copy->getBrain()->setIdea(0, "I want sleep");

    std::cout << std::endl;
    std::cout << "Original idea: " 
              << original->getBrain()->getIdea(0) << std::endl;
    std::cout << std::endl;
    delete original;
    
    std::cout << std::endl;
    std::cout << "Copy idea: " 
              << copy->getBrain()->getIdea(0) << std::endl;
    std::cout << std::endl;
    delete copy;

    std::cout << std::endl;
    std::cout << "--- Desctructors ---"<< std::endl;

    for (int i = 0; i < 4; i++)
        delete animals[i];
}
