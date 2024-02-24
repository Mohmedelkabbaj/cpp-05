/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-kabb <mel-kabb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 01:51:00 by mel-kabb          #+#    #+#             */
/*   Updated: 2024/02/24 01:52:43 by mel-kabb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

// Constructors

PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm", 25, 5), target("default")
{
    std::cout << "PresidentialPardonForm Default Constructor called" << std::endl;
};

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("PresidentialPardonForm", 25, 5), target(target)
{
    std::cout << "PresidentialPardonForm Parameterized Constructor called" << std::endl;
};

//  copy Constructor

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &rhs) : AForm(rhs.getName(), rhs.getGradeToSign(), rhs.getGradeToExecute())
{
    std::cout << "PresidentialPardonForm Copy Constructor called" << std::endl;
    *this = rhs;
};

// Overload Assignation operator

PresidentialPardonForm &PresidentialPardonForm::operator=(PresidentialPardonForm const &rhs)
{
    std::cout << "PresidentialPardonForm Assignation operator called" << std::endl;
    if (this != &rhs)
        this->target = rhs.target;
    return (*this);
};

// Destructor

PresidentialPardonForm::~PresidentialPardonForm()
{
    std::cout << "PresidentialPardonForm Destructor called" << std::endl;
};

void PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
    if (!this->getIsSigned())
        throw AForm::FormNotSignedException();
    else if (executor.getGrade() > this->getGradeToExecute())
        throw AForm::GradeTooLowException();
    std::cout << this->target << " has been pardoned by Zafod Beeblebrox" << std::endl;
};
