/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgertrud <lgertrud@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 16:10:29 by lgertrud          #+#    #+#             */
/*   Updated: 2026/04/03 15:28:07 by lgertrud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
	try
	{
		Bureaucrat a("Joao", 148);
		std::cout << a << std::endl;

		a.decrementGrade();
		std::cout << a << std::endl;

		a.decrementGrade();
		std::cout << a << std::endl;
		a.decrementGrade();

	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}