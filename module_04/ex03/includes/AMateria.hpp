/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nzharkev <nzharkev@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-04-08 12:03:06 by nzharkev          #+#    #+#             */
/*   Updated: 2025-04-08 12:03:06 by nzharkev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <string>

class ICharacter;

class AMateria
{
    protected:
        std::string _Type;
    public:
        AMateria();
        AMateria(std::string const &type);
        AMateria(const AMateria &copy);
        AMateria& operator=(const AMateria &copy);
        virtual ~AMateria();
        std::string getType();
        virtual AMateria* clone() const = 0;
        virtual void use(ICharacter &target);
};