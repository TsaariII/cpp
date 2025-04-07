/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nzharkev <nzharkev@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 13:16:36 by nzharkev          #+#    #+#             */
/*   Updated: 2025/04/03 14:16:12 by nzharkev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap("Dname_clap_name"), _Name("Dname")
{
    std::cout << "\033[4;34mConstructed default DiamondTrap named " << _Name << "\033[0m" << std::endl;
    _HitPoint = FragTrap::_HitPoint;
    _EnergyPoint = ScavTrap::_EnergyPoint;
    _Attack = FragTrap::_Attack;
}
DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name"), _Name(name)
{
    std::cout << "\033[4;36mConstructed DiamondTrap named " << _Name << "\033[0m" << std::endl; 
    _HitPoint = FragTrap::_HitPoint;
    _EnergyPoint = ScavTrap::_EnergyPoint;
    _Attack = ScavTrap::_Attack;
}
DiamondTrap::DiamondTrap(const DiamondTrap &copy) : ClapTrap(copy), ScavTrap(copy), FragTrap(copy), _Name(copy._Name) {
    std::cout << "\033[4;94mConstructed copy Diamondtrap named " << _Name << "\033[0m" << std::endl; }
DiamondTrap &DiamondTrap::operator=(const DiamondTrap &copy)
{
    std::cout << "\033[4;33mDiamondTrap Assignment operator called\033[0m" << std::endl;
    if (this != &copy)
    {
        ClapTrap::operator=(copy);
        ScavTrap::operator=(copy);
        FragTrap::operator=(copy);
        this->_Name = copy._Name;
    } 
    return *this;
}
DiamondTrap::~DiamondTrap() { std::cout << "\033[4;31mDestructed DiamondTrap named " << _Name << "\033[0m" << std::endl; }
void DiamondTrap::whoAmI() { std::cout << "\033[95mI am " << _Name << " and my ClapTrap name is " << ClapTrap::_Name << "\033[0m" << std::endl; };