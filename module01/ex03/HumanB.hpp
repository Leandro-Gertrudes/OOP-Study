/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgertrud <lgertrud@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 11:49:30 by lgertrud          #+#    #+#             */
/*   Updated: 2025/10/23 12:00:06 by lgertrud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
#define HUMANB_HPP

#endif

#include "Weapon.hpp"

class HumanB
{
	private:
		std::string name;
		Weapon *arms;
	public:
	HumanB(std::string newName);
	void attack();
	void setWeapon(Weapon &wea);
};