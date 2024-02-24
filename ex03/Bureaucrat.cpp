/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-kabb <mel-kabb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 03:09:58 by mel-kabb          #+#    #+#             */
/*   Updated: 2024/02/24 03:10:02 by mel-kabb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"

// Constructors
Bureaucrat::Bureaucrat()
{
	std::cout << "Bureaucrat Default Constructor called" << std::endl;
};

// parameterized Constructors
Bureaucrat::Bureaucrat(std::string const name, int grade) : name(name)
{
	std::cout << "Bureaucrat Parameterized Constructor called" << std::endl;
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	else
		this->grade = grade;
};

//  copy Constructor
Bureaucrat::Bureaucrat(Bureaucrat const &rhs) : name(rhs.name)
{
	std::cout << "Bureaucrat Copy Constructor called" << std::endl;
	*this = rhs;
};

// Overload Assignation operator
Bureaucrat &Bureaucrat::operator=(Bureaucrat const &rhs)
{
	std::cout << "Bureaucrat Assignation operator called" << std::endl;
	if (this != &rhs)
		this->grade = rhs.grade;
	return (*this);
};

// Destructor
Bureaucrat::~Bureaucrat()
{
	std::cout << "Bureaucrat Destructor called" << std::endl;
};

// Getter
std::string Bureaucrat::getName() const
{
	return (this->name);
};

int Bureaucrat::getGrade() const
{
	return (this->grade);
};

// Member function
void Bureaucrat::incrementGrade()
{
	if (this->grade - 1 < 1)
		throw Bureaucrat::GradeTooHighException();
	else
		this->grade--;
};

void Bureaucrat::decrementGrade()
{
	if (this->grade + 1 > 150)
		throw Bureaucrat::GradeTooLowException();
	else
		this->grade++;
};

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Grade too high");
};

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Grade too low");
};

// operator
std::ostream &operator<<(std::ostream &o, const Bureaucrat &rhs)
{
	o << rhs.getName() << ", Bureaucrat grade " << rhs.getGrade() << std::endl;
	return (o);
};

void Bureaucrat::signForm(AForm &form)
{
	form.beSigned(*this);
	if (form.getIsSigned())
		std::cout << this->getName() << " signed " << form.getName() << std::endl;
	else
		std::cout << this->getName() << " couldn’t sign  " << form.getName() << " because "
				  << " grade is too low" << std::endl;
}

void Bureaucrat::executeForm(AForm const &form)
{
	try
	{
		form.execute(*this);
		std::cout << this->getName() << " executes " << form.getName() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << this->getName() << " couldn’t execute " << form.getName() << " because " << e.what() << std::endl;
	}
};