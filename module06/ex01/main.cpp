/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgertrud <lgertrud@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/16 14:57:22 by lgertrud          #+#    #+#             */
/*   Updated: 2026/04/16 14:57:24 by lgertrud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main()
{
    Data data;

    data.id = 42;
    data.name = "Braga";

    // original pointer
    Data* originalPtr = &data;

    // serialize
    uintptr_t raw = Serializer::serialize(originalPtr);

    // deserialize
    Data* newPtr = Serializer::deserialize(raw);

    std::cout << "Original pointer: " << originalPtr << std::endl;
    std::cout << "Serialized value: " << raw << std::endl;
    std::cout << "Deserialized pointer: " << newPtr << std::endl;

    std::cout << "\nData check:\n";
    std::cout << "ID: " << newPtr->id << std::endl;
    std::cout << "Name: " << newPtr->name << std::endl;

    return 0;
}