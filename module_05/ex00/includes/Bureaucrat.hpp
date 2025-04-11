/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nzharkev <nzharkev@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-04-11 07:57:00 by nzharkev          #+#    #+#             */
/*   Updated: 2025-04-11 07:57:00 by nzharkev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <string>
#include <stdexcept>

class Bureaucrat
{
    private:
        const std::string _Name;
        const int _Grade;
    public:
        Bureaucrat();
        Bureaucrat(std::string name, int grade);
        Bureaucrat(const Bureaucrat &copy);
        Bureaucrat& operator=(const Bureaucrat &copy);
        ~Bureaucrat();
        class GradeTooHighExecption : public std::exception
        {
            public:
                const char* what() const throw();
        };
        std::string getName() const;
        int getGrade() const;
        void setName(std::string name);
        void setGrade(int grade);
};