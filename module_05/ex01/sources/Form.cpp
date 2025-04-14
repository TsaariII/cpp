/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nzharkev <nzharkev@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-04-14 08:56:46 by nzharkev          #+#    #+#             */
/*   Updated: 2025-04-14 08:56:46 by nzharkev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Form.hpp"

Form::Form() : _Name("The Form"), _Signed(0), _SignGrade(10), _ExeGrade(10) { std::cout << "The Form was created" << std::endl; }

Form::Form(std::string name, bool signature, int sGrade, int eGrade) : _Name(name), _Signed(signature), _SignGrade(sGrade), _ExeGrade(eGrade)
{
    if (_SignGrade < 1 || _ExeGrade < 1)
        throw GradeTooHighExecption();
    if (_SignGrade > 150 || _ExeGrade > 150)
        throw GradeTooLowExecption();
    std::cout << this->getName() << " form was created with grade "
              << this->getSignGrade() << " to sign and grade "
              << this->getExeGrade() << " for execute" << std::endl;
}

Form::Form(const Form &copy) : _Name(copy._Name), _Signed(copy._Signed), _SignGrade(copy._SignGrade), _ExeGrade(copy._ExeGrade)
{
    std::cout << "Copy of " << copy.getName() << " form was created" << std::endl;
}

Form& Form::operator=(const Form &copy)
{
    if (this != &copy)
    {
        _Signed = copy._Signed;
    }
    std::cout << "Successfully copied bureaucrat " << copy.getName()
    << " with assignment operator" << std::endl;
    return *this;
}

Form::~Form() { std::cout << this->getName() << " form was sherred" << std::endl; }

const char* Form::GradeTooHighExecption::what() const noexcept { return "What are these random grades here? You know better that 1 is the highest"; }


const char* Form::GradeTooLowExecption::what() const noexcept { return "Didn't you listen at all? 150 that's the lowest you can go"; }

std::string Form::getName() const { return _Name; }

bool Form::getSigned() { return _Signed; }

int Form::getSignGrade() const { return _SignGrade; }

int Form::getExeGrade() const { return _ExeGrade; }

void Form::beSigned(Bureaucrat& b)
{
    if (b.getGrade() <= _SignGrade)
        _Signed = true;
    else
        throw GradeTooLowExecption();
}

std::ostream& operator<<(std::ostream &out, Form& f)
{
    out << "Name: " << f.getName() 
        << "\nGrade needed to sign form: " << f.getSignGrade()
        << "\nGrade needed to execute form: " << f.getExeGrade()
        << "\nSigned status: " << f.getSigned() << std::endl;
    return out;
}