/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-kabb <mel-kabb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 03:38:20 by mel-kabb          #+#    #+#             */
/*   Updated: 2024/02/24 03:38:21 by mel-kabb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm() : name("default"), isSigned(false), gradeToSign(1), gradeToExecute(1){};

AForm::AForm(std::string const name, int gradeToSign, int gradeToExecute) : name(name), isSigned(false), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute)
{
    if (gradeToSign < 1 || gradeToExecute < 1)
        throw AForm::GradeTooHighException();
    else if (gradeToSign > 150 || gradeToExecute > 150)
        throw AForm::GradeTooLowException();
};

AForm::AForm(AForm const &src) : name(src.name), isSigned(src.isSigned), gradeToSign(src.gradeToSign), gradeToExecute(src.gradeToExecute){};

AForm &AForm::operator=(AForm const &rhs)
{
    if (this != &rhs)
    {
        this->isSigned = rhs.isSigned;
    }
    return (*this);
};

AForm::~AForm(){};

std::string AForm::getName() const
{
    return (this->name);
};

bool AForm::getIsSigned() const
{
    return (this->isSigned);
};

int AForm::getGradeToSign() const
{
    return (this->gradeToSign);
};

int AForm::getGradeToExecute() const
{
    return (this->gradeToExecute);
};

void AForm::beSigned(Bureaucrat &bureaucrat)
{
    if (bureaucrat.getGrade() <= this->gradeToSign)
        this->isSigned = true;
    else
        throw AForm::GradeTooLowException();
};

const char *AForm::GradeTooHighException::what() const throw()
{
    return "Grade is too high";
};

const char *AForm::GradeTooLowException::what() const throw()
{
    return "Grade is too low";
};

const char *AForm::FormNotSignedException::what() const throw()
{
    return "Form is not signed";
};

std::ostream &operator<<(std::ostream &out, AForm const &src)
{
    out << src.getName() << ", Form grade to sign " << src.getGradeToSign() << ", grade to execute " << src.getGradeToExecute() << ", is signed " << src.getIsSigned() << std::endl;
    return (out);
};
