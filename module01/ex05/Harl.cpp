/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgertrud <lgertrud@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 17:29:17 by lgertrud          #+#    #+#             */
/*   Updated: 2025/10/31 16:35:11 by lgertrud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

void Harl::complain(std::string level)
{
    std::string levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};

    void (Harl::*functions[])(void) = {
        &Harl::debug,
        &Harl::info,
        &Harl::warning,
        &Harl::error
    };

    for (int i = 0; i < 4; i++)
    {
        if (levels[i] == level)
        {
            (this->*functions[i])();
            return;
        }
    }

    std::cout << "Unknown level: " << level << std::endl;
}

void Harl::debug( void ) 
{
	std::cout << DEBUG << std::endl;
}

void Harl::info( void )
{
	std::cout << INFO << std::endl;
}

void Harl::warning( void )
{
	std::cout << WARNING << std::endl;
}

void Harl::error( void )
{
	std::cout << ERROR << std::endl;
}
