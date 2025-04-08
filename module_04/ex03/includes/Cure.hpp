/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nzharkev <nzharkev@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-04-08 12:48:06 by nzharkev          #+#    #+#             */
/*   Updated: 2025-04-08 12:48:06 by nzharkev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "AMateria.hpp"

class Cure : public AMateria
{
    public:

        Cure();
        Cure(const Cure &copy);
        Cure& operator=(const Cure &copy);
        ~Cure();
        virtual AMateria* clone() const;
};