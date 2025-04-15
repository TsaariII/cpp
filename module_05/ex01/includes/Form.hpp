/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nzharkev <nzharkev@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 08:52:56 by nzharkev          #+#    #+#             */
/*   Updated: 2025/04/15 13:05:34 by nzharkev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "Bureaucrat.hpp"

class Form
{
    private:
        const std::string _Name;
        bool _Signed;
        const int _SignGrade;
        const int _ExeGrade;
    public:
        Form();
        Form(std::string name, int sGrade, int eGrade);
        Form(const Form &copy);
        Form& operator=(const Form &copy);
        ~Form();
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
        bool getSigned() const;
        int getSignGrade() const;
        int getExeGrade() const;
        void beSigned(Bureaucrat& b);
};