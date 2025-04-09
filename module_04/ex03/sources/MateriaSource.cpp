/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nzharkev <nzharkev@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-04-08 13:54:38 by nzharkev          #+#    #+#             */
/*   Updated: 2025-04-08 13:54:38 by nzharkev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/MateriaSource.hpp"

MateriaSource::MateriaSource()
{
    for (int i = 0; i < 4; i++)
        _Materias[i] = nullptr;
}

MateriaSource::MateriaSource(MateriaSource &copy)
{
    if (this != &copy)
    {
        for (int i = 0; i < 4; i++)
        {
            if (_Materias[i])
                delete _Materias[i];
            if (copy._Materias[i])
                _Materias[i] = copy._Materias[i]->clone();
            else
                _Materias[i] = nullptr;
        }
    }
}

MateriaSource& MateriaSource::operator=(const MateriaSource &copy)
{
    if (this != &copy)
    {
        for (int i = 0; i < 4; i++)
        {
            if (_Materias[i])
                delete _Materias[i];
            if (copy._Materias[i])
                _Materias[i] = copy._Materias[i]->clone();
            else
                _Materias[i] = nullptr;
        }
    }
    return *this;
}

MateriaSource::~MateriaSource()
{
    for (int i = 0; i < 4; i++)
    {
        if (_Materias[i])
            delete _Materias[i];
    }
}

void MateriaSource::learnMateria(AMateria* m)
{
    for (int i = 0; i < 4; i++)
    {
        if (!_Materias[i])
        {
            _Materias[i] = m;
            return ;
        }
    }
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
    for (int i = 0; i < 4; i++)
    {
        if (_Materias[i] && (_Materias[i]->getType() == type))
            return _Materias[i]->clone();
    }
    return 0;
}