/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-kabb <mel-kabb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 01:27:52 by mel-kabb          #+#    #+#             */
/*   Updated: 2024/02/24 01:49:03 by mel-kabb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

// Constructors

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45), target("default")
{
    std::cout << "RobotomyRequestForm Default Constructor called" << std::endl;
};

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequestForm", 72, 45), target(target)
{
    std::cout << "RobotomyRequestForm Parameterized Constructor called" << std::endl;
};

//  copy Constructor

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &rhs) : AForm(rhs.getName(), rhs.getGradeToSign(), rhs.getGradeToExecute())
{
    std::cout << "RobotomyRequestForm Copy Constructor called" << std::endl;
    *this = rhs;
};

// Overload Assignation operator

RobotomyRequestForm &RobotomyRequestForm::operator=(RobotomyRequestForm const &rhs)
{
    std::cout << "RobotomyRequestForm Assignation operator called" << std::endl;
    if (this != &rhs)
        this->target = rhs.target;
    return (*this);
};

// Destructor

RobotomyRequestForm::~RobotomyRequestForm()
{
    std::cout << "RobotomyRequestForm Destructor called" << std::endl;
};

void RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
    std::srand(std::time(0));
    if (!this->getIsSigned())
        throw AForm::FormNotSignedException();
    else if (executor.getGrade() > this->getGradeToExecute())
        throw AForm::GradeTooLowException();
    else if (rand() % 2)
        std::cout << this->target << " has been robotomized successfully" << std::endl;
    else
        std::cout << this->target << " robotomization failed" << std::endl;
};
