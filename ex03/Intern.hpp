/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-kabb <mel-kabb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 03:19:56 by mel-kabb          #+#    #+#             */
/*   Updated: 2024/02/24 03:32:23 by mel-kabb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define INTERN_HPP

#include <iostream>
#include <string>
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

class Intern
{
private:
    AForm *createPresidentialPardonForm(std::string target);
    AForm *createRobotomyRequestForm(std::string target);
    AForm *createShrubberyCreationForm(std::string target);

public:
    Intern();
    Intern(const Intern &src);
    ~Intern();
    Intern &operator=(const Intern &src);
    AForm *makeForm(std::string Nameform, std::string target);
    class FormNotFoundException : public std::exception
    {
    public:
        virtual const char *what() const throw();
    };
};

#endif