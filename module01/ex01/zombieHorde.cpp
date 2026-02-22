/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgertrud <lgertrud@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 16:31:25 by lgertrud          #+#    #+#             */
/*   Updated: 2025/11/05 13:50:56 by lgertrud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name )
{
    Zombie *newHorde = new Zombie[N];
	
	for(int i = 0; i < N; i++)
	{
		newHorde[i].setName(name);
	}
	return (newHorde);
}
