/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgertrud <lgertrud@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 16:58:59 by lgertrud          #+#    #+#             */
/*   Updated: 2026/03/18 17:03:26 by lgertrud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

// CANONICAL

Form::Form() : name("default"), isSigned(false), gradeToSign(75), gradeToExecute(75) {}

Form::Form(const std::string name, int gradeToSign, int gradeToExecute)
    : name(name), isSigned(false), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute)
{
    if (gradeToSign < 1 || gradeToExecute < 1)
        throw GradeTooHighException();
    if (gradeToSign > 150 || gradeToExecute > 150)
        throw GradeTooLowException();
}

Form::Form(const Form &other)
    : name(other.name),
      isSigned(other.isSigned),
      gradeToSign(other.gradeToSign),
      gradeToExecute(other.gradeToExecute)
{
}

Form &Form::operator=(const Form &other)
{
    if (this != &other)
    {
        this->isSigned = other.isSigned;
        // const attributes não mudam
    }
    return *this;
}

Form::~Form() {}


// GETTERS

std::string Form::getName() const
{
    return this->name;
}

bool Form::getIsSigned() const
{
    return this->isSigned;
}

int Form::getGradeToSign() const
{
    return this->gradeToSign;
}

int Form::getGradeToExecute() const
{
    return this->gradeToExecute;
}


// CORE FUNCTION

void Form::beSigned(const Bureaucrat &b)
{
    if (b.getGrade() <= this->gradeToSign)
        this->isSigned = true;
    else
        throw GradeTooLowException();
}


// EXCEPTIONS

const char* Form::GradeTooHighException::what() const throw()
{
    return "Form grade too high!";
}

const char* Form::GradeTooLowException::what() const throw()
{
    return "Form grade too low!";
}


// OPERATOR <<

std::ostream &operator<<(std::ostream &out, const Form &f)
{
    out << f.getName()
        << ", form signed: " << (f.getIsSigned() ? "yes" : "no")
        << ", grade to sign: " << f.getGradeToSign()
        << ", grade to execute: " << f.getGradeToExecute();
    return out;
}