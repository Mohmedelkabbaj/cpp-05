/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-kabb <mel-kabb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 01:13:01 by mel-kabb          #+#    #+#             */
/*   Updated: 2024/02/24 01:27:01 by mel-kabb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

// Constructors

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137), target("default")
{
    std::cout << "ShrubberyCreationForm Default Constructor called" << std::endl;
};

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreationForm", 145, 137), target(target)
{
    std::cout << "ShrubberyCreationForm Parameterized Constructor called" << std::endl;
};

//  copy Constructor

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &rhs) : AForm(rhs.getName(), rhs.getGradeToSign(), rhs.getGradeToExecute())
{
    std::cout << "ShrubberyCreationForm Copy Constructor called" << std::endl;
    *this = rhs;
};

// Overload Assignation operator

ShrubberyCreationForm &ShrubberyCreationForm::operator=(ShrubberyCreationForm const &rhs)
{
    std::cout << "ShrubberyCreationForm Assignation operator called" << std::endl;
    if (this != &rhs)
        this->target = rhs.target;
    return (*this);
};

// Destructor

ShrubberyCreationForm::~ShrubberyCreationForm()
{
    std::cout << "ShrubberyCreationForm Destructor called" << std::endl;
};

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
    if (!this->getIsSigned())
        throw AForm::FormNotSignedException();
    else if (executor.getGrade() > this->getGradeToExecute())
        throw AForm::GradeTooLowException();
    std::ofstream file;
    file.open(this->target + "_shrubbery");
    file << "                                                         ." << std::endl;
    file << "                                              .         ;" << std::endl;
    file << "                 .              .              ;%     ;;" << std::endl;
    file << "                   ,           ,                :;%  %;" << std::endl;
    file << "                    :         ;                   :;%;'     ." << std::endl;
    file << "           ,.        %;     %;            ;        %;'    ,;" << std::endl;
    file << "             ;       ;%;  %%;        ,     %;    ;%;    ,%'" << std::endl;
    file << "              %;       %;%;      ,  ;       %;  ;%;   ,%;" << std::endl;
    file << "               ;%;      %;        ;%;        % ;%;  ,%;" << std::endl;
    file << "                `%;.     ;%;     %;'         `;%%;.%;'" << std::endl;
    file << "                 `:;%.    ;%%. %@;        %; ;@%;%'" << std::endl;
    file << "                    `:%;.  :;bd%;          %;@%;'" << std::endl;
    file << "                      `@%:.  :;%.         ;@@%;" << std::endl;
    file << "                        `@%.  `;@%.      ;@@%;" << std::endl;
    file << "                          `@%%. `@%%    ;@@%;" << std::endl;
    file << "                            ;@%. :@%%  %@@%;" << std::endl;
    file << "                              %@bd%%%bd%%:;" << std::endl;
    file << "                                #@%%%%%:;;" << std::endl;
    file << "                                %@@%%%::;" << std::endl;
    file << "                                %@@@%(o);  . '         " << std::endl;
    file << "                                %@@@o%;:(.,'         " << std::endl;
    file << "                            `.. %@@@o%::;         " << std::endl;
    file << "                               `)@@@o%::;         " << std::endl;
    file << "                                %@@(o)::;        " << std::endl;
    file << "                               .%@@@@%::;         " << std::endl;
    file << "                              ;%@@@@%::;.          " << std::endl;
    file << "                             ;%@@@@%%:;;;. " << std::endl;
    file << "                         ...;%@@@@@%%:;;;;,.. " << std::endl;
    file.close();
};
