/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nzharkev <nzharkev@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 07:57:00 by nzharkev          #+#    #+#             */
/*   Updated: 2025/04/15 13:27:00 by nzharkev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <string>
#include <stdexcept>
#include <iostream>
// #include "Form.hpp"

class Form;

class Bureaucrat
{
    private:
        const std::string _Name;
        int _Grade;
    public:
        Bureaucrat();
        Bureaucrat(std::string name, int grade);
        Bureaucrat(const Bureaucrat &copy);
        Bureaucrat& operator=(const Bureaucrat &copy);
        ~Bureaucrat();
        class GradeTooHighExeception : public std::exception
        {
            public:
                const char* what() const noexcept;
        };
        class GradeTooLowExeception : public std::exception
        {
            public:
                const char* what() const noexcept;
        };
        std::string getName() const;
        int getGrade() const;
        void setGrade(int grade);
        void incrementGrade();
        void decrementGrade();
        void signForm(Form &f);
};

std::ostream& operator<<(std::ostream& out, const Bureaucrat& b);