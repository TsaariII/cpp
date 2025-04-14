/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nzharkev <nzharkev@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-04-14 08:52:56 by nzharkev          #+#    #+#             */
/*   Updated: 2025-04-14 08:52:56 by nzharkev         ###   ########.fr       */
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
        Form(std::string name, bool signature, int sGrade, int eGrade);
        Form(const Form &copy);
        Form& operator=(const Form &copy);
        ~Form();
        class GradeTooHighExecption : public std::exception
        {
            public:
                const char* what() const noexcept;
        };
        class GradeTooLowExecption : public std::exception
        {
            public:
                const char* what() const noexcept;
        };
        std::string getName() const;
        bool getSigned();
        int getSignGrade() const;
        int getExeGrade() const;
        void beSigned(Bureaucrat& b);
};