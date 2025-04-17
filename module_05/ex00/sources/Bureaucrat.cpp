/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nzharkev <nzharkev@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 08:06:21 by nzharkev          #+#    #+#             */
/*   Updated: 2025/04/17 14:42:39 by nzharkev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _Name("Basic Brueaucrat"), _Grade(10)
{
    if (_Grade < 1)
        throw GradeTooHighExeception();
    if (_Grade > 150)
       throw GradeTooLowExeception();
    std::cout << "Default bureaucrat " << this->getName() <<  " created with grade "
              << this->getGrade() << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _Name(name), _Grade(grade)
{
    if (_Grade < 1)
        throw GradeTooHighExeception();
    if (_Grade > 150)
        throw GradeTooLowExeception();
    std::cout << "Bureaucrat " << this->getName() << " created with grade " << this->getGrade() << std::endl;
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
    std::cout << "Copy of bureaucrat " << copy.getName() << " with name "
              << this->getName()
              <<  " was created with assignment operator" << std::endl;
    return *this;
}

Bureaucrat::~Bureaucrat() { std::cout << "Time to clockout " << _Name << "!" << std::endl; }

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

const char* Bureaucrat::GradeTooHighExeception::what() const noexcept { return "Grade too high: Bureaucrats can't be *more* than perfect (minimum is 1)"; }

const char* Bureaucrat::GradeTooLowExeception::what() const noexcept { return "Grade too low: Bureaucrats can't sink below rock bottom (maximum is 150)"; }


std::ostream& operator<<(std::ostream &out, const Bureaucrat& b)
{
    out << b.getName() << ", bureaucrat grade " << b.getGrade();
    return out;
}
