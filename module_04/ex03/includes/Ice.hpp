/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nzharkev <nzharkev@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-04-08 12:15:01 by nzharkev          #+#    #+#             */
/*   Updated: 2025-04-08 12:15:01 by nzharkev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "AMateria.hpp"

class Ice : public AMateria
{
    protected:
        std::string _Type;
    public:
        Ice();
        Ice(const Ice &copy);
        Ice& operator=(const Ice &copy);
        ~Ice();
        virtual AMateria* clone() const;
};