/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgertrud <lgertrud@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 16:10:31 by lgertrud          #+#    #+#             */
/*   Updated: 2026/04/03 14:04:56 by lgertrud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

// CANONICAL

Bureaucrat::Bureaucrat() : name("default"), grade(75) {}

Bureaucrat::Bureaucrat(const std::string name, int grade) : name(name)
{
	if (grade < 1)
		throw GradeTooHighException();
	if (grade > 150)
		throw GradeTooLowException();
	this->grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat &other)
	: name(other.name), grade(other.grade) {}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other)
{
	if (this != &other)
		this->grade = other.grade;
	return *this;
}

Bureaucrat::~Bureaucrat() {}


// GETTERS

std::string Bureaucrat::getName() const
{
	return this->name;
}

int Bureaucrat::getGrade() const
{
	return this->grade;
}


// ACTIONS

void Bureaucrat::incrementGrade()
{
	if (this->grade <= 1)
		throw GradeTooHighException();
	this->grade--;
}

void Bureaucrat::decrementGrade()
{
	if (this->grade >= 150)
		throw GradeTooLowException();
	this->grade++;
}


// SIGN FORM

void Bureaucrat::signForm(AForm &form)
{
	try
	{
		form.beSigned(*this);
		std::cout << this->name << " signed " << form.getName() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << this->name << " couldn’t sign "
				  << form.getName() << " because "
				  << e.what() << std::endl;
	}
}


// EXECUTE FORM

void Bureaucrat::executeForm(AForm const & form) const
{
	try
	{
		form.execute(*this);
		std::cout << this->name << " executed " << form.getName() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << this->name << " couldn’t execute "
				  << form.getName() << " because "
				  << e.what() << std::endl;
	}
}


// EXCEPTIONS

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return "Grade too high!";
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return "Grade too low!";
}


// OPERATOR <<

std::ostream &operator<<(std::ostream &out, const Bureaucrat &b)
{
	out << b.getName() << ", bureaucrat grade " << b.getGrade() << ".";
	return out;
}