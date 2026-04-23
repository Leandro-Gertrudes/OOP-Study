/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgertrud <lgertrud@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/23 15:33:18 by lgertrud          #+#    #+#             */
/*   Updated: 2026/04/23 16:16:43 by lgertrud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"
#include <iostream>

int main(int, char**)
{
    std::cout << "---testing with INT---\n\n";
    try
    {
        Array<int> test(2);
        std::cout << "size = " << test.size() << std::endl;
        test[0] = 4;
        test[1] = 2;
        std::cout << "test[0] && test[1] = " << test[0] << test[1] << std::endl;
        std::cout << "trying to put a data in index 3\n";
        test[3] = 1;
    }
    catch(std::exception& e){
        std::cout << e.what();
    }
    
    std::cout << "\n\n---testing with string---\n\n";

    try
    {
        Array<std::string> testStr(2);
        std::cout << "size = " << testStr.size() << std::endl;
        testStr[0] = "Hello";
        testStr[1] = "World!!";
        std::cout << "test[0] && test[1] = " << testStr[0] << " " << testStr[1] << std::endl;
        std::cout << "trying to put a data in index 3\n";
        testStr[3] = 1;
    }
    catch(std::exception& e){
        std::cout << e.what();
    }
}