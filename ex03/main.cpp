/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-kabb <mel-kabb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 03:44:44 by mel-kabb          #+#    #+#             */
/*   Updated: 2024/02/24 04:41:38 by mel-kabb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

int main()
{
    try
    {
        Bureaucrat b("bureaucrat", 1);
        Intern someRandomIntern;
        AForm *rrf;

        rrf = someRandomIntern.makeForm("robotomy request", "Bender");
        // delete rrf;
        rrf = someRandomIntern.makeForm("presidential pardon", "Bender");
        // delete rrf;
        rrf = someRandomIntern.makeForm("shrubbery creation", "Bender");
        b.executeForm(*rrf);
        delete rrf;
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
    return (0);
}