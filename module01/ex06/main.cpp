/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgertrud <lgertrud@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 12:29:40 by lgertrud          #+#    #+#             */
/*   Updated: 2025/10/24 13:47:51 by lgertrud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(int argc, char **argv)
{
	if(argc != 2)
		return (0);

	Harl	h;
	int		level = -1;

	std::string arg = argv[1];
    std::string levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};

    for (int i = 0; i < 4; i++)
    {
		if(arg == levels[i])
		{
			level = i + 1;
			break ;
		}
    }

	switch (level) {
	case 1:
		h.complain("DEBUG");
	case 2:
		h.complain("INFO");
	case 3:
		h.complain("WARNING");
	case 4:
		h.complain("ERROR");
		break ;
	default:
		h.complain("nothing");
	}
}
