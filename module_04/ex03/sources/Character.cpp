/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nzharkev <nzharkev@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-04-08 13:04:32 by nzharkev          #+#    #+#             */
/*   Updated: 2025-04-08 13:04:32 by nzharkev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Character.hpp"
#include "../includes/AMateria.hpp"

Character::Character() : _Name("Name")
{
    for (int i = 0; i < 4; i++)
        _Inventory[i] = nullptr;
}

Character::Character(std::string name) : _Name(name)
{
    for (int i = 0; i < 4; i++)
        _Inventory[i] = nullptr;
}

Character::Character(const Character &copy)
{
    if (this != &copy)
    {
        _Name = copy._Name;
        for (int i = 0; i < 4; i++)
        {
            if (_Inventory[i])
                delete _Inventory[i];
            if (copy._Inventory[i])
                _Inventory[i] = copy._Inventory[i]->clone();
            else
                _Inventory[i] = nullptr;
        }
    }
}

Character& Character::operator=(const Character &copy)
{
    if (this != &copy)
    {
        _Name = copy._Name;
        for (int i = 0; i < 4; i++)
        {
            if (_Inventory[i])
                delete _Inventory[i];
            if (copy._Inventory[i])
                _Inventory[i] = copy._Inventory[i]->clone();
            else
                _Inventory[i] = nullptr;
        }
    }
    return *this;
}

Character::~Character()
{
    for (int i = 0; i < 4; i++)
    {
        if (_Inventory[i])
            delete _Inventory[i];
    }
}

std::string const &Character::getName() const { return _Name; }

void Character::equip(AMateria* m)
{
    for (int i = 0; i < 4; i++)
    {
        if (!_Inventory[i])
        {
            _Inventory[i] = m;
            return ;
        }
    }
}

void Character::unequip(int idx)
{
    if (idx >= 0 && idx < 4)
        _Inventory[idx] = nullptr;
}

void Character::use(int idx, ICharacter& target)
{
    if (idx >= 0 && idx < 4 && _Inventory[idx])
        _Inventory[idx]->use(target);
}