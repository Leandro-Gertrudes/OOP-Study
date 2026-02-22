/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgertrud <lgertrud@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 12:29:40 by lgertrud          #+#    #+#             */
/*   Updated: 2025/11/02 16:15:21 by lgertrud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main()
{
	Harl h;

	h.complain("ERROR");
	h.complain("WARNING");
	h.complain("DEBUG");
	h.complain("INFO");
	h.complain("nothing");
}