/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-kabb <mel-kabb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 03:38:09 by mel-kabb          #+#    #+#             */
/*   Updated: 2024/02/24 03:38:11 by mel-kabb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

// Constructors
Form::Form() : name("default"), isSigned(false), gradeToSign(0), gradeToExecute(0)
{
    std::cout << "Form Default Constructor called" << std::endl;
};

Form::Form(std::string const name, int gradeToSign, int gradeToExecute) : name(name), isSigned(false), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute)
{
    std::cout << "Form Parameterized Constructor called" << std::endl;
    if (gradeToSign < 1 || gradeToExecute < 1)
        throw Form::GradeTooHighException();
    else if (gradeToSign > 150 || gradeToExecute > 150)
        throw Form::GradeTooLowException();
}
//! check this
Form::Form(Form const &src) : name(src.name), isSigned(src.isSigned), gradeToSign(src.gradeToSign), gradeToExecute(src.gradeToExecute)
{
    std::cout << "Form Copy Constructor called" << std::endl;
};

// Overload Assignation operator

Form &Form::operator=(Form const &rhs)
{
    std::cout << "Form Assignation operator called" << std::endl;
    if (this != &rhs)
    {
        this->isSigned = rhs.isSigned;
    }
    return (*this);
};

// Destructor

Form::~Form()
{
    std::cout << "Form Destructor called" << std::endl;
};

// Getter

std::string Form::getName() const
{
    return (this->name);
};

bool Form::getIsSigned() const
{
    return (this->isSigned);
};

int Form::getGradeToSign() const
{
    return (this->gradeToSign);
};

int Form::getGradeToExecute() const
{
    return (this->gradeToExecute);
}
void Form::beSigned(Bureaucrat &bureaucrat)
{
    if (bureaucrat.getGrade() <= this->gradeToSign)
        this->isSigned = true;
    else
        throw Form::GradeTooLowException();
};

const char *Form::GradeTooHighException::what() const throw()
{
    return "Grade is too high";
};

const char *Form::GradeTooLowException::what() const throw()
{
    return "Grade is too low";
};

// Member function

std::ostream &operator<<(std::ostream &out, Form const &src)
{
    out << "Form " << src.getName() << " is signed: " << src.getIsSigned() << " and requires grade to sign: " << src.getGradeToSign() << " and grade to execute: " << src.getGradeToExecute() << std::endl;
    return (out);
}
