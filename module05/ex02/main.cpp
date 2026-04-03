/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgertrud <lgertrud@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 16:10:29 by lgertrud          #+#    #+#             */
/*   Updated: 2026/04/03 16:17:03 by lgertrud         ###   ########.fr       */
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

	ShrubberyCreationForm s("home");
	RobotomyRequestForm r("Bender");
	PresidentialPardonForm p("Marvin");

	b.signForm(s);
	b.executeForm(s);

	b.signForm(r);
	b.executeForm(r);

	b.signForm(p);
	b.executeForm(p);
}