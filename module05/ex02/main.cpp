/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgertrud <lgertrud@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 16:10:29 by lgertrud          #+#    #+#             */
/*   Updated: 2026/04/09 15:03:10 by lgertrud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "AForm.hpp"

int main()
{
	Bureaucrat b("Boss", 1);
	//Bureaucrat j("john", 50);

	ShrubberyCreationForm s("home");
	RobotomyRequestForm r("Bender");
	PresidentialPardonForm p("Marvin");

	b.signForm(s);
	b.executeForm(s);
	std::cout  << std::endl;
	
 	b.signForm(r);
	b.executeForm(r);
	std::cout  << std::endl;
	b.signForm(p);
	b.executeForm(p);
}