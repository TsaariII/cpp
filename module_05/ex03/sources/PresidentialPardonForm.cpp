/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nzharkev <nzharkev@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 17:05:51 by nzharkev          #+#    #+#             */
/*   Updated: 2025/04/17 14:06:52 by nzharkev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("PPF-1", 25, 5), _Target("Default")
{
    std::cout << "Default Presidential Pardon Form created" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("PPF-42T", 25, 5), _Target(target)
{
    std::cout << "Presidential Pardon Form for " << _Target << " created" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm &copy) : AForm(copy), _Target(copy._Target)
{
    std::cout << "Form " << copy.getName() << " form created" << std::endl;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(PresidentialPardonForm &copy)
{
    if (this != &copy)
        _Target = copy._Target;
    std::cout << "Copy of form " << copy.getName() << " with name "
              << this->getName() << " for " << _Target
              <<  " created with assignment operator" << std::endl;
    return *this;
}

PresidentialPardonForm::~PresidentialPardonForm() { std::cout << "Form " << this->getName() << " has been archived" << std::endl; }

std::string PresidentialPardonForm::getTarget() const { return _Target; }

void PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
    if (this->getSigned() == "no")
        throw NotSignedExeception();
    if (executor.getGrade() > this->getExeGrade())
        throw GradeTooLowExeception();
    std::cout << _Target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}
