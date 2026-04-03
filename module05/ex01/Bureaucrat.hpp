/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgertrud <lgertrud@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 15:56:14 by lgertrud          #+#    #+#             */
/*   Updated: 2026/04/03 15:43:46 by lgertrud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <exception>

class Form;

class Bureaucrat{
	private:
		const std::string	name;
		int					grade;
	public:
		Bureaucrat();
		Bureaucrat(const std::string name, int grade);
		Bureaucrat(const Bureaucrat &other);
		Bureaucrat &operator=(const Bureaucrat &other);

		//
		std::string getName() const;
		int			getGrade() const;
		void		signForm(Form &form);

		void		incrementGrade();
		void		decrementGrade();

		class GradeTooHighException : public std::exception{
			public:
				const char* what() const throw();
		};

		class GradeTooLowException : public std::exception{
			public:
				const char* what() const throw();
		};

		~Bureaucrat();
};

std::ostream &operator<<(std::ostream &out, const Bureaucrat &b);

#endif