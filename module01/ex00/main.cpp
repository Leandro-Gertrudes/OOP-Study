/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgertrud <lgertrud@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 14:55:29 by lgertrud          #+#    #+#             */
/*   Updated: 2025/10/27 13:58:48 by lgertrud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
	Zombie *zombieHeap;

	zombieHeap = newZombie("Rick grimes");
	zombieHeap->announce();
	delete zombieHeap;

	randomChump("Carl Grimes");	
}
