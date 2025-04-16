/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nzharkev <nzharkev@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 08:56:46 by nzharkev          #+#    #+#             */
/*   Updated: 2025/04/15 13:13:56 by nzharkev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/AForm.hpp"

AForm::AForm() : _Name("The Form"), _Signed(0), _SignGrade(10), _ExeGrade(10) { std::cout << "The Form was created" << std::endl; }

AForm::AForm(std::string name, int sGrade, int eGrade) : _Name(name), _Signed(false), _SignGrade(sGrade), _ExeGrade(eGrade)
{
    if (_SignGrade < 1 || _ExeGrade < 1)
        throw GradeTooHighExeception();
    if (_SignGrade > 150 || _ExeGrade > 150)
        throw GradeTooLowExeception();
    std::cout << this->getName() << " form was created with grade "
              << this->getSignGrade() << " to sign and grade "
              << this->getExeGrade() << " for execute" << std::endl;
}

AForm::AForm(const AForm &copy) : _Name(copy._Name + "_copy"), _Signed(copy._Signed), _SignGrade(copy._SignGrade), _ExeGrade(copy._ExeGrade)
{
    std::cout << "Copy of " << copy.getName() << " form was created" << std::endl;
}

AForm& AForm::operator=(const AForm &copy)
{
    if (this != &copy)
    {
        _Signed = copy._Signed;
    }
    std::cout << "Successfully copied bureaucrat " << copy.getName()
    << " with assignment operator" << std::endl;
    return *this;
}

AForm::~AForm() { std::cout << "AForm " << this->getName() << " has been archived" << std::endl; }

const char* AForm::GradeTooHighExeception::what() const noexcept { return "What this this? You know that 1 is the highest"; }


const char* AForm::GradeTooLowExeception::what() const noexcept { return "Didn't you listen at all? This isn't for you"; }

const char* AForm::NotSignedExeception::what() const noexcept { return "So you just ignored or didn't want to see that there is no signature?"; }

std::string AForm::getName() const { return _Name; }

bool AForm::getSigned() const { return _Signed; }

int AForm::getSignGrade() const { return _SignGrade; }

int AForm::getExeGrade() const { return _ExeGrade; }

void AForm::beSigned(Bureaucrat& b)
{
    if (b.getGrade() <= _SignGrade)
        _Signed = true;
    else
        throw GradeTooLowExeception();
}

std::ostream& operator<<(std::ostream &out, AForm& f)
{
    out << "Name: " << f.getName() 
        << "\nGrade needed to sign form: " << f.getSignGrade()
        << "\nGrade needed to execute form: " << f.getExeGrade()
        << "\nSigned status: " << f.getSigned() << std::endl;
    return out;
}