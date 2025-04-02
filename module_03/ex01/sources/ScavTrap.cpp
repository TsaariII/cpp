/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nzharkev <nzharkev@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 14:13:00 by nzharkev          #+#    #+#             */
/*   Updated: 2025/04/02 14:40:32 by nzharkev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap("Default")
{
    _HitPoint = 100;
    _EnergyPoint = 50;
    _Attack = 20;
    std::cout << "Constructed default ClapTrap named " << _Name << std::endl;
}

ScavTrap::ScavTrap(std::string name)
{
    _HitPoint = 100;
    _EnergyPoint = 50;
    _Attack = 20;
    std::cout << "Constructed ClapTrap named " << _Name << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &copy) : ClapTrap(copy) { std::cout << "Constructed copy Claptrap named" << _Name << std::endl; }

ScavTrap& ScavTrap::operator=(const ScavTrap &copy)
{
    std::cout << "ScavTrap assignament operator called" << std::endl;
    ClapTrap::operator=(copy);
    return *this;
}

ScavTrap::~ScavTrap() { std::cout << "Destructed ScavTrap named " << _Name << std::endl; }

void ScavTrap::attack(const std::string &target)
{
    if (_HitPoint > 0 && _EnergyPoint > 0)
    {
        std::cout << "ClapTrap " << _Name << " attacks " <<  target
                << " , causing " << _Attack << " points of damage!"
                << std::endl;
    }
    else if (_EnergyPoint == 0)
        std::cout << "ClapTrap " << _Name << " has no energy to attack!" << std::endl;
    else
        std::cout << "ClapTrap " << _Name << " could't attack!" << std::endl;
}

void ScavTrap::guardGate()
{
    if (_OnDuty == false)
    {
        if (_HitPoint > 0 && _EnergyPoint > 0)
        {
            std::cout << "ScavTrap " << _Name << " is guarding the gate" << std::endl;
            _EnergyPoint--;
        }
        else
            std::cout << "Reason we don't know ScavTrap " << _Name << " can't bother to to gurad gate" << std::endl;
    }
    else
        std::cout << "ScavTrap " << _Name << " is already on duty";
}