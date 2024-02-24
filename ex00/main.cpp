/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-kabb <mel-kabb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 03:37:50 by mel-kabb          #+#    #+#             */
/*   Updated: 2024/02/24 04:55:13 by mel-kabb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
	try
	{
		Bureaucrat b("mohamed", 3);
		std::cout << b << std::endl;
		b.incrementGrade();
		std::cout << b << std::endl;
		b.decrementGrade();
		std::cout << b << std::endl;
	}
	catch (Bureaucrat::GradeTooHighException &e)
	{
		std::cout << e.what() << std::endl;
	}
	catch (Bureaucrat::GradeTooLowException &e)
	{
		std::cout << e.what() << std::endl;
	}

	// try {
	// Bureaucrat b("ash", 1);

	// std::cout << b << std::endl;

	// b.incrementGrade();
	// b.decrementGrade();
	// } catch (b::GradeTooHighException &e) {
	//     std::cout << e.what() << std::endl;
	// }
	return (0);
}