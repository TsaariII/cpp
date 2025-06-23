/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nzharkev <nzharkev@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 15:03:34 by nzharkev          #+#    #+#             */
/*   Updated: 2025/05/01 11:10:17 by nzharkev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Intern.hpp"
#include "../includes/PresidentialPardonForm.hpp"
#include "../includes/RobotomyRequestForm.hpp"
#include "../includes/ShrubberyCreationForm.hpp"

Intern::Intern() { std::cout << "Intern hired" << std::endl; }

Intern::Intern(Intern &copy) { *this = copy; std::cout << "Copied intern" << std::endl; }

Intern& Intern::operator=(Intern &copy) { (void)copy; std::cout << "Copied intern with assignment" << std::endl; return *this; }

Intern::~Intern() { std::cout << "Intern fired. No forms were harmed in the process." << std::endl; }

static AForm* writePPF(std::string target)
{
    std::cout << "Intern created Presidential Pardon Form" << std::endl;
    AForm* ppf = new PresidentialPardonForm(target);
    return ppf;
}
static AForm* writeRRF(std::string target)
{
    std::cout << "Intern created Robotomy Request Form" << std::endl;
    AForm* rrf = new RobotomyRequestForm(target);
    return rrf;
}
static AForm* writeSCF(std::string target)
{
    std::cout << "Inter created Shrubbery Creation Form" << std::endl;
    AForm* scf = new ShrubberyCreationForm(target);
    return scf;
}

AForm* Intern::makeForm(std::string form, std::string target)
{
    typedef AForm* (*FormList) (std::string);
    FormList forms[3] = { writePPF, writeRRF, writeSCF};
    std::string list[3] = {"presidential pardon", "robotomy request", "shrubbery" };
    for (int i = 0; i < 3; i++)
    {
        if (form == list[i])
            return forms[i](target);
    }
    throw Intern::NonExistingFormException();
    return NULL;
}