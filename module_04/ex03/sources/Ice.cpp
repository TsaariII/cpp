/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nzharkev <nzharkev@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-04-08 12:30:46 by nzharkev          #+#    #+#             */
/*   Updated: 2025-04-08 12:30:46 by nzharkev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Ice.hpp"

Ice::Ice() : AMateria("ice") {}

Ice::Ice(const Ice &copy) : AMateria(copy) {}

Ice& Ice::operator=(const Ice &copy)
{
    if (this != &copy)
        AMateria::operator=(copy);
    return *this;
}

Ice::~Ice() {}

AMateria* Ice::clone() const { return new Ice(); }