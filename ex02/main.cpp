/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-kabb <mel-kabb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 02:01:14 by mel-kabb          #+#    #+#             */
/*   Updated: 2024/02/24 03:19:08 by mel-kabb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"

int main()
{
    try
    {
        Bureaucrat b1("b1", 1);
        Bureaucrat b2("b2", 150);
        PresidentialPardonForm f1("f1");
        RobotomyRequestForm f2("f2");
        ShrubberyCreationForm f3("f3");

        std::cout << b1 << std::endl;
        std::cout << b2 << std::endl;
        std::cout << f1 << std::endl;
        std::cout << f2 << std::endl;
        std::cout << f3 << std::endl;

        b1.signForm(f1);
        b1.signForm(f2);
        b1.signForm(f3);

        b1.executeForm(f1);
        b1.executeForm(f2);
        b1.executeForm(f3);

        b2.signForm(f1);
        b2.signForm(f2);
        b2.signForm(f3);

        b2.executeForm(f1);
        b2.executeForm(f2);
        b2.executeForm(f3);
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
    return 0;
}