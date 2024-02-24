/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-kabb <mel-kabb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 03:19:50 by mel-kabb          #+#    #+#             */
/*   Updated: 2024/02/24 04:13:47 by mel-kabb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern()
{
}

Intern::Intern(const Intern &src)
{
    *this = src;
}

Intern::~Intern()
{
}

Intern &Intern::operator=(const Intern &src)
{
    (void)src;
    return *this;
}

AForm *Intern::createPresidentialPardonForm(std::string target)
{
    return new PresidentialPardonForm(target);
}

AForm *Intern::createRobotomyRequestForm(std::string target)
{
    return new RobotomyRequestForm(target);
}

AForm *Intern::createShrubberyCreationForm(std::string target)
{
    return new ShrubberyCreationForm(target);
}

AForm *Intern::makeForm(std::string Nameform, std::string target)
{
    std::string forms[3] = {"presidential pardon", "robotomy request", "shrubbery creation"};
    AForm *(Intern::*form[3])(std::string target) = {&Intern::createPresidentialPardonForm, &Intern::createRobotomyRequestForm, &Intern::createShrubberyCreationForm};
    for (int i = 0; i < 3; i++)
    {
        if (Nameform == forms[i])
        {
            std::cout << "Intern creates " << Nameform << std::endl;
            return (this->*form[i])(target);
        }
    }
    throw FormNotFoundException();
}

const char *Intern::FormNotFoundException::what() const throw()
{
    return "Form not found";
}
