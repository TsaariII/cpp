/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nzharkev <nzharkev@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-04-08 12:53:04 by nzharkev          #+#    #+#             */
/*   Updated: 2025-04-08 12:53:04 by nzharkev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Cure.hpp"

Cure::Cure() : AMateria("cure") {}

Cure::Cure(const Cure &copy) : AMateria(copy) {}

Cure& Cure::operator=(const Cure &copy)
{
    if (this != &copy)
        AMateria::operator=(copy);
    return *this;
}

Cure::~Cure() {}

AMateria* Cure::clone() const { return new Cure(); }