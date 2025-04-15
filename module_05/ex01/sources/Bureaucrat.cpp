/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nzharkev <nzharkev@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 08:06:21 by nzharkev          #+#    #+#             */
/*   Updated: 2025/04/15 13:07:03 by nzharkev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Bureaucrat.hpp"
#include "../includes/Form.hpp"

Bureaucrat::Bureaucrat() : _Name("Basic Brueaucrat"), _Grade(10)
{
    if (_Grade < 1)
        throw GradeTooHighExeception();
    if (_Grade > 150)
       throw GradeTooLowExeception();
    std::cout << "Default bureaucrat " << this->getName() <<  " was created with grade "
              << this->getGrade() << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _Name(name), _Grade(grade)
{
    if (_Grade < 1)
        throw GradeTooHighExeception();
    if (_Grade > 150)
        throw GradeTooLowExeception();
    std::cout << "Bureaucrat " << this->getName() << " constructed with grade " << this->getGrade() << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &copy) : _Name(copy._Name), _Grade(copy._Grade)
{
    if (_Grade < 1)
        throw GradeTooHighExeception();
    if (_Grade > 150)
       throw GradeTooLowExeception();
    std::cout << "Successfully copied bureaucrat " << copy.getName() << std::endl; 
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat &copy)
{
    if (this != &copy)
    {
         _Grade = copy._Grade;
        if (_Grade < 1)
            throw GradeTooHighExeception();
        if (_Grade > 150)
            throw GradeTooLowExeception();
    }
    std::cout << "Successfully copied bureaucrat " << copy.getName()
              << " with assignment operator" << std::endl;
    return *this;
}

Bureaucrat::~Bureaucrat() { std::cout << "Time to clockout!" << std::endl; }

std::string Bureaucrat::getName() const { return _Name; }

int Bureaucrat::getGrade() const { return _Grade; }

void Bureaucrat::setGrade(int grade)
{
    _Grade = grade;
    if (_Grade < 1)
        throw GradeTooHighExeception();
    if (_Grade > 150)
       throw GradeTooLowExeception();
}

void Bureaucrat::incrementGrade()
{
    _Grade--;
    if (_Grade < 1)
        throw GradeTooHighExeception();
}

void Bureaucrat::decrementGrade()
{
    _Grade++;
    if (_Grade > 150)
        throw GradeTooLowExeception();
}

void Bureaucrat::signForm(Form &f)
{
    if (f.getSigned() == false)
    {
        if (this->getGrade() > f.getSignGrade())
        {
            std::cout << this->getName() << " couldn't sign the form "
                      << f.getName() << " because signature grade is higher than grade of " << this->getName() << std::endl;
            return ;
        }
        f.beSigned(*this);
        std::cout << this->getName() << " signed form " << f.getName() << std::endl;
        return ;
    }
    else
        std::cout << this->getName() << " couldn't sign the form beacause it's already signed" << std::endl;
}

const char* Bureaucrat::GradeTooHighExeception::what() const noexcept { return "You already reached the top. What else want??"; }

const char* Bureaucrat::GradeTooLowExeception::what() const noexcept { return "You are lowest of the lowest. There is nothing below you"; }


std::ostream& operator<<(std::ostream &out, const Bureaucrat& b)
{
    out << b.getName() << ", bureaucrat grade " << b.getGrade() << ".";
    return out;
}
