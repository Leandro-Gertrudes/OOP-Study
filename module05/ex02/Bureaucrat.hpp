/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgertrud <lgertrud@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 15:56:14 by lgertrud          #+#    #+#             */
/*   Updated: 2026/04/03 13:55:15 by lgertrud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <exception>

class AForm; // forward declaration

class Bureaucrat
{
	private:
		const std::string	name;
		int					grade;

	public:
		// CANONICAL
		Bureaucrat();
		Bureaucrat(const std::string name, int grade);
		Bureaucrat(const Bureaucrat &other);
		Bureaucrat &operator=(const Bureaucrat &other);
		~Bureaucrat();

		// GETTERS
		std::string getName() const;
		int getGrade() const;

		// ACTIONS
		void incrementGrade();
		void decrementGrade();

		void signForm(AForm &form);
		void executeForm(AForm const & form) const;

		// EXCEPTIONS
		class GradeTooHighException : public std::exception{
			public:
				const char* what() const throw();
		};

		class GradeTooLowException : public std::exception{
			public:
				const char* what() const throw();
		};
};

// OPERATOR
std::ostream &operator<<(std::ostream &out, const Bureaucrat &b);

#endif