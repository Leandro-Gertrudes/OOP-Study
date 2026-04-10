/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgertrud <lgertrud@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/03 13:50:25 by lgertrud          #+#    #+#             */
/*   Updated: 2026/04/09 14:47:32 by lgertrud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(const std::string target)
    : AForm("Shrubbery", 145, 137), target(target) {}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
    if (!getIsSigned())
        throw FormNotSignedException();
    if (executor.getGrade() > getGradeToExecute())
        throw GradeTooLowException();

    std::ofstream file((target + "_shrubbery").c_str());
    file << "       *       "  << "       *       " << "       *       " <<  std::endl;
    file << "      ***      "  << "      ***      " << "      ***      " <<  std::endl;
    file << "     *****     "  << "     *****     " << "     *****     " <<  std::endl;
    file << "    *******    "  << "    *******    " << "    *******    " <<  std::endl;
    file << "   *********   "  << "   *********   " << "   *********   " <<  std::endl;
    file << "  ***********  "  << "  ***********  " << "  ***********  " <<  std::endl;
    file << "      |||      "  << "      |||      " << "      |||      " <<  std::endl;
    file << "      |||      "  << "      |||      " << "      |||      " <<  std::endl;
}