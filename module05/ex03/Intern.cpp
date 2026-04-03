/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgertrud <lgertrud@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/03 14:45:27 by lgertrud          #+#    #+#             */
/*   Updated: 2026/04/03 14:55:58 by lgertrud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

// CANONICAL

Intern::Intern() {}

Intern::Intern(const Intern &other)
{
	(void)other;
}

Intern &Intern::operator=(const Intern &other)
{
	(void)other;
	return *this;
}

Intern::~Intern() {}


//
AForm* createShrubbery(std::string target)
{
	return new ShrubberyCreationForm(target);
}

AForm* createRobotomy(std::string target)
{
	return new RobotomyRequestForm(target);
}

AForm* createPardon(std::string target)
{
	return new PresidentialPardonForm(target);
}

AForm* Intern::makeForm(std::string name, std::string target)
{
	std::string forms[3] = {
		"shrubbery creation",
		"robotomy request",
		"presidential pardon"
	};

	AForm* (*creators[3])(std::string) = {
		createShrubbery,
		createRobotomy,
		createPardon
	};

	for (int i = 0; i < 3; i++)
	{
		if (forms[i] == name)
		{
			std::cout << "Intern creates " << name << std::endl;
			return creators[i](target);
		}
	}

	std::cout << "Error: unknown form name" << std::endl;
	return NULL;
}