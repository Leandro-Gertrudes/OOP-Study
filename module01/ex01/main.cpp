/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgertrud <lgertrud@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 14:55:29 by lgertrud          #+#    #+#             */
/*   Updated: 2025/11/05 14:19:27 by lgertrud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
	Zombie *horde;

	int N = 10;

	horde = zombieHorde(N, "Horde");
	for(int i = 0; i < N; i++)
		horde[i].announce();

	delete[] horde;
}
