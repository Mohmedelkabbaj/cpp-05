/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-kabb <mel-kabb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 03:38:15 by mel-kabb          #+#    #+#             */
/*   Updated: 2024/02/24 04:46:02 by mel-kabb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

int main()
{
    try
    {
        Bureaucrat bureaucrat("bureaucrat", 1);
        Form form("form", 96, 1);

        std::cout << "grade : " << form.getGradeToSign() << std::endl;

        std::cout << bureaucrat << std::endl;
        std::cout << form << std::endl;
        bureaucrat.signForm(form);
        std::cout << form << std::endl;
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
    return (0);
}