/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nzharkev <nzharkev@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 14:13:00 by nzharkev          #+#    #+#             */
/*   Updated: 2025/04/03 13:01:20 by nzharkev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap() { std::cout << "\033[1;34mConstructed default FragTrap named " << _Name << "\033[0m" << std::endl; }

FragTrap::FragTrap(std::string name) : ClapTrap(name) { std::cout << "\033[1;36mConstructed FragTrap named " << _Name << "\033[0m" << std::endl; }

FragTrap::FragTrap(const FragTrap &copy) : ClapTrap(copy) { std::cout << "\033[1;94mConstructed copy FragTrap named " << _Name << "\033[0m" << std::endl; }

FragTrap& FragTrap::operator=(const FragTrap &copy)
{
    std::cout << "\033[1;33mFragTrap assignament operator called\033[0m" << std::endl;
    ClapTrap::operator=(copy);
    return *this;
}

FragTrap::~FragTrap() { std::cout << "\033[1;31mDestructed FragTrap named " << _Name << "\033[0m" << std::endl; }

void FragTrap::attack(const std::string &target)
{
    if (_HitPoint > 0 && _EnergyPoint > 0)
    {
        std::cout << "\033[1;96mFragTrap " << _Name << " attacks " <<  target
                << ", causing " << _Attack << " points of damage!\033[0m"
                << std::endl;
        _EnergyPoint--;
    }
    else if (_EnergyPoint == 0)
        std::cout << "\033[1;96;41mFragTrap " << _Name << " has no energy to attack!\033[0m" << std::endl;
    else
        std::cout << "\033[1mFragTrap " << _Name << " couldn't attack!\033[0m" << std::endl;
}

void FragTrap::highFivesGuys(void)
{
    if (_HitPoint > 0 && _EnergyPoint > 0)
    {
        std::cout << "\033[1;32mFragTrap " << _Name << " throws their hand in the air and yells:\nHigh five!\033[0m"
        << " *SLAP*" << std::endl;
    }
    else
        std::cout << "\033[1;31mFragTrap " << _Name << " is unable to do this\033[0m" << std::endl;
}