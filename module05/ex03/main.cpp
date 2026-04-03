/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgertrud <lgertrud@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 16:10:29 by lgertrud          #+#    #+#             */
/*   Updated: 2026/04/03 14:42:13 by lgertrud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "Bureaucrat.hpp"

int main()
{
	Intern someRandomIntern;
	AForm* form;

	form = someRandomIntern.makeForm("robotomy request", "Bender");

	if (form)
	{
		Bureaucrat b("Boss", 1);
		b.signForm(*form);
		b.executeForm(*form);
		delete form;
	}
}