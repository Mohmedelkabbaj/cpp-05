/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-kabb <mel-kabb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 03:38:42 by mel-kabb          #+#    #+#             */
/*   Updated: 2024/02/24 04:44:49 by mel-kabb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include <string>
#include <exception>
#include "Bureaucrat.hpp"

class AForm
{
private:
    std::string const name;
    bool isSigned;
    int const gradeToSign;
    int const gradeToExecute;

public:
    AForm();
    AForm(std::string const name, int gradeToSign, int gradeToExecute);
    AForm(AForm const &src);
    AForm &operator=(AForm const &src);
    std::string getName() const;
    bool getIsSigned() const;
    int getGradeToSign() const;
    int getGradeToExecute() const;
    void beSigned(Bureaucrat &bureaucrat);
    virtual void execute(Bureaucrat const &executor) const = 0;
    class GradeTooHighException : public std::exception
    {
    public:
        virtual const char *what() const throw();
    };
    class GradeTooLowException : public std::exception
    {
    public:
        virtual const char *what() const throw();
    };
    class FormNotSignedException : public std::exception
    {
    public:
        virtual const char *what() const throw();
    };
    virtual ~AForm();
};

std::ostream &operator<<(std::ostream &out, AForm const &src);

#endif