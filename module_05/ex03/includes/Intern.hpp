/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nzharkev <nzharkev@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 14:49:28 by nzharkev          #+#    #+#             */
/*   Updated: 2025/05/01 11:02:52 by nzharkev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <string>

class AForm;

class Intern
{
    public:
        Intern();
        Intern(Intern &copy);
        Intern& operator=(Intern &copy);
        ~Intern();
        AForm* makeForm(std::string form, std::string target);
        class NonExistingFormException : public std::exception
        {
            public:
                virtual const char* what() const throw()
                {
                    return "You can't just make up forms. There is three forms I have and that's it";
                }
        };
};