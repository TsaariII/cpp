/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nzharkev <nzharkev@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-04-11 08:06:21 by nzharkev          #+#    #+#             */
/*   Updated: 2025-04-11 08:06:21 by nzharkev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _Name("Basic Brueaucrat"), _Grade(10) {}
Bureaucrat::Bureaucrat(std::string name, int grade) : _Name(name), _Grade(grade) {}
Bureaucrat::Bureaucrat(const Bureaucrat &copy) : _Name(copy._Name), _Grade(copy._Grade) {}
Bureaucrat& Bureaucrat::operator=(const Bureaucrat &copy)
{
    if (this != &copy)
    {
        _Name = copy._Name;
        _Grade = copy._Grade;
    }
    return *this;
}
Bureaucrat::~Bureaucrat() {}
std::string Bureaucrat::getName() const { return _Name; }
int Bureaucrat::getGrade() const { return _Grade; }
void Bureaucrat::setName(std::string name) { _Name = name; }
void Bureaucrat::setGrade(int grade) { _Grade = grade; }