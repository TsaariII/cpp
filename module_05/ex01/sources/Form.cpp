/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nzharkev <nzharkev@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 08:56:46 by nzharkev          #+#    #+#             */
/*   Updated: 2025/04/17 14:07:12 by nzharkev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Form.hpp"

Form::Form() : _Name("The Form"), _Signed(0), _SignGrade(10), _ExeGrade(10) { std::cout << "The Form created" << std::endl; }

Form::Form(std::string name, int sGrade, int eGrade) : _Name(name), _Signed(false), _SignGrade(sGrade), _ExeGrade(eGrade)
{
    if (_SignGrade < 1 || _ExeGrade < 1)
        throw GradeTooHighExeception();
    if (_SignGrade > 150 || _ExeGrade > 150)
        throw GradeTooLowExeception();
    std::cout << this->getName() << " form created with grade "
              << this->getSignGrade() << " to sign and grade "
              << this->getExeGrade() << " for execute" << std::endl;
}

Form::Form(const Form &copy) : _Name(copy._Name), _Signed(copy._Signed), _SignGrade(copy._SignGrade), _ExeGrade(copy._ExeGrade)
{
    std::cout << "Form " << copy.getName() << " form created" << std::endl;
}

Form& Form::operator=(const Form &copy)
{
    if (this != &copy)
    {
        _Signed = copy._Signed;
    }
    std::cout << "Copy of form " << copy.getName() << " with name "
              << this->getName() << " for "
              <<  " was created with assignment operator" << std::endl;
    return *this;
}

Form::~Form() { std::cout << this->getName() << " form was sherred" << std::endl; }

const char* Form::GradeTooHighExeception::what() const noexcept { return "Form error: grade is too high"; }

const char* Form::GradeTooLowExeception::what() const noexcept { return "Form error: grade is too low"; }

std::string Form::getName() const { return _Name; }

bool Form::getSigned() const { return _Signed; }

int Form::getSignGrade() const { return _SignGrade; }

int Form::getExeGrade() const { return _ExeGrade; }

void Form::beSigned(Bureaucrat& b)
{
    if (b.getGrade() <= _SignGrade)
        _Signed = true;
    else
        throw GradeTooLowExeception();
}

std::ostream& operator<<(std::ostream &out, Form& f)
{
    out << "Name: " << f.getName() 
        << "\nGrade needed to sign form: " << f.getSignGrade()
        << "\nGrade needed to execute form: " << f.getExeGrade()
        << "\nSigned status: " << f.getSigned() << std::endl;
    return out;
}