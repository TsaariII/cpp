/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ICharacter.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nzharkev <nzharkev@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-04-08 12:10:29 by nzharkev          #+#    #+#             */
/*   Updated: 2025-04-08 12:10:29 by nzharkev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "AMateria.hpp"

class ICharacter
{
    public:
         virtual ~ICharacter() {}
         virtual std::string const & getName() const = 0;
         virtual void equip(AMateria* m) = 0;
         virtual void unequip(int idx) = 0;
         virtual void use(int idx, ICharacter& target) = 0;
};