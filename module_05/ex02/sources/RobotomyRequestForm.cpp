/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nzharkev <nzharkev@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 11:04:49 by nzharkev          #+#    #+#             */
/*   Updated: 2025/04/17 14:16:44 by nzharkev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/RobotomyRequestForm.hpp"
#include <random>

RobotomyRequestForm::RobotomyRequestForm() : AForm("RRF-1", 72, 45), _Target("Default")
{
    std::cout << "Default Robotomy Request Form created" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RRF-56D", 72, 45), _Target(target)
{
    std::cout << "Robotomy Request Form for " << _Target << " created" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm &copy) : AForm(copy), _Target(copy._Target)
{
    std::cout << "Form " << copy.getName() << " form created" << std::endl;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(RobotomyRequestForm &copy)
{
    if (this != &copy)
    {
        _Target = copy._Target;
    }
    
    std::cout << "Copy of form " << copy.getName() << " with name "
              << this->getName() << " for " << _Target
              <<  " created with assignment operator" << std::endl;
    return *this;
}

RobotomyRequestForm::~RobotomyRequestForm() { std::cout << "Form " << this->getName() << " has been archived" << std::endl; }

std::string RobotomyRequestForm::getTarget() const { return _Target; }

void RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
    if (this->getSigned() == "no")
        throw NotSignedExeception();
    if (executor.getGrade() > this->getExeGrade())
        throw GradeTooLowExeception();
    static std::random_device rd;
    static std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(0, 1);
    std::cout << "BzzzzzzzZZZzzZZZzzz..." << std::endl;
    if (dist(gen))
        std::cout << _Target << " has been robotomized successfully!" << std::endl;
    else
        std::cout << "The robotomy of " << _Target << " failed." << std::endl;
}