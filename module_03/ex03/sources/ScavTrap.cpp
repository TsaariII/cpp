/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nzharkev <nzharkev@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 14:13:00 by nzharkev          #+#    #+#             */
/*   Updated: 2025/04/03 12:39:16 by nzharkev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap()
{
    std::cout << "\033[3;34mConstructed default ScavTrap named " << _Name << "\033[0m" << std::endl;
    _OnDuty = false;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
    std::cout << "\033[3;36mConstructed ScavTrap named " << _Name << "\033[0m" << std::endl;
    _OnDuty = false;
}

ScavTrap::ScavTrap(const ScavTrap &copy) : ClapTrap(copy) { std::cout << "\033[3;94mConstructed copy Scavtrap named " << _Name << "\033[0m" << std::endl; }

ScavTrap& ScavTrap::operator=(const ScavTrap &copy)
{
    std::cout << "\033[3;33mScavTrap assignament operator called\033[0m" << std::endl;
    ClapTrap::operator=(copy);
    return *this;
}

ScavTrap::~ScavTrap() { std::cout << "\033[3;31mDestructed ScavTrap named " << _Name << "\033[0m" << std::endl; }

void ScavTrap::attack(const std::string &target)
{
    if (_HitPoint > 0 && _EnergyPoint > 0)
    {
        std::cout << "\033[3;96mScavTrap " << _Name << " attacks " <<  target
                << ", causing " << _Attack << " points of damage!\033[0m"
                << std::endl;
        _EnergyPoint--;
    }
    else if (_EnergyPoint == 0)
        std::cout << "\033[3;96;41mScavTrap " << _Name << " has no energy to attack!\033[0m" << std::endl;
    else
        std::cout << "\033[3mScavTrap " << _Name << " could't attack!\033[0m" << std::endl;
}

void ScavTrap::guardGate()
{
    if (_OnDuty == false)
    {
        if (_HitPoint > 0 && _EnergyPoint > 0)
        {
            std::cout << "\033[3;97mScavTrap " << _Name << " is guarding the gate\033[0m" << std::endl;
            _OnDuty = true;
            _EnergyPoint--;
        }
        else
            std::cout << "\033[3;95mReasons we don't know ScavTrap " << _Name << " can't bother to to gurad gate\033[0m" << std::endl;
    }
    else
        std::cout << "\033[3;37mScavTrap " << _Name << " is already on duty\033[0m" << std::endl;
}