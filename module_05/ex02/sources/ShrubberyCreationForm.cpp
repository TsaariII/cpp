/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nzharkev <nzharkev@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 12:50:37 by nzharkev          #+#    #+#             */
/*   Updated: 2025/04/17 14:15:54 by nzharkev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("SCF-1", 145, 137), _Target("Default")
{
    std::cout << "Default Shrubbery Creation Form created" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("SCF-75J", 145, 137), _Target(target)
{
    std::cout << "Shrubbery Creation Form for " << _Target << " created" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm &copy)  : AForm(copy), _Target(copy._Target)
{
    std::cout << "Form " << copy.getName() << " form created" << std::endl;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(ShrubberyCreationForm &copy)
{
    if (this != &copy)
        _Target = copy._Target;
        std::cout << "Copy of form " << copy.getName() << " with name "
        << this->getName() << " for " << _Target
        <<  " created with assignment operator" << std::endl;
    return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() { std::cout << "Form " << this->getName() << " has been archived" << std::endl; }

std::string ShrubberyCreationForm::getTarget() const { return _Target; }

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
    if (this->getSigned() == "no")
        throw NotSignedExeception();
    if (executor.getGrade() > this->getExeGrade())
        throw GradeTooLowExeception();
    std::ofstream file(_Target + "_shrubbery");
    file << "       ccee88oo\n"
         << "    C8O8O8Q8PoOb o8oo\n"
         << "  dOB69QO8PdUOpugoO9bD\n"
         << "CgggbU8OU qOp qOdoUOdcb\n"
         << "    6OuU  /p u gcoUodpP\n"
         << "      \\\\//  /douUP\n"
         << "        \\\\\\////\n"
         << "         |||/\\\n"
         << "         |||\\/ \n"
         << "         |||||\n"
         << "   .....//||||\\\\...." << std::endl;
    file.close();
    std::cout << "Shrubbery created successfully: " << _Target + "_shrubbery" << std::endl;
}
