/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nzharkev <nzharkev@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-04-08 12:22:52 by nzharkev          #+#    #+#             */
/*   Updated: 2025-04-08 12:22:52 by nzharkev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/AMateria.hpp"
#include "../includes/ICharacter.hpp"

AMateria::AMateria() : _Type("materia") {}
AMateria::AMateria(std::string const &type) : _Type(type) {}
AMateria::AMateria(const AMateria &copy)
{
    if (this != &copy)
        *this =copy;
}
AMateria& AMateria::operator=(const AMateria &copy)
{
    (void)copy;
    return *this;
}
AMateria::~AMateria() {}

std::string AMateria::getType() { return _Type; }

void AMateria::use(ICharacter &target)
{
    if (_Type == "ice")
        std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
    else if (_Type == "cure")
        std::cout << "* heals " << target.getName() << "’s wounds *" << std::endl;
}