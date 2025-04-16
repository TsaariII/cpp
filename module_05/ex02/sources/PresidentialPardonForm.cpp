/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nzharkev <nzharkev@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 17:05:51 by nzharkev          #+#    #+#             */
/*   Updated: 2025/04/15 17:12:11 by nzharkev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("PPF-42T", 25, 5), _Target("Default")
{
    std::cout << "Default Presidential Pardon Form was created" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("PPF-42T", 25, 5), _Target(target)
{
    std::cout << "Presidential Pardon Form for " << _Target << " was created" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm &copy) : AForm(copy), _Target(copy._Target)
{
    std::cout << "Copy of " << this->getName() << " for " << _Target <<  " form was created" << std::endl;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(PresidentialPardonForm &copy)
{
    if (this != &copy)
        _Target = copy._Target;
    std::cout << "Copy of " << this->getName() << " for " << _Target <<  " form was created with assignment operator" << std::endl;
    return *this;
}

PresidentialPardonForm::~PresidentialPardonForm() { std::cout << "Form " << this->getName() << " has been archived" << std::endl; }

std::string PresidentialPardonForm::getTarget() const { return _Target; }

void PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
    if (this->getSigned() == true)
    {
        if (executor.getGrade() > this->getExeGrade())
            throw GradeTooLowExeception();
        else
            std::cout << _Target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
    }
    else
        throw NotSignedExeception();
}