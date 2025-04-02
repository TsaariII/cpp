/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nzharkev <nzharkev@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 10:00:57 by nzharkev          #+#    #+#             */
/*   Updated: 2025/04/02 14:30:44 by nzharkev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ClapTrap.hpp"

ClapTrap::ClapTrap() : _Name("Name"), _HitPoint(10), _EnergyPoint(10), _Attack(0) {
    std::cout << "Constructed default ClapTrap named " << _Name << std::endl;
}

ClapTrap::ClapTrap(std::string name) : _Name(name), _HitPoint(10), _EnergyPoint(10), _Attack(0) {
    std::cout << "Constructed ClapTrap named " << _Name << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &copy) : _Name(copy._Name), _HitPoint(copy._HitPoint), _EnergyPoint(copy._EnergyPoint), _Attack(copy._Attack) {
    std::cout << "Constructed copy Claptrap named" << _Name << std::endl; 
}

ClapTrap& ClapTrap::operator=(const ClapTrap &copy) {
    std::cout << "ClapTrap assignament operator called" << std::endl;
    this->_Name = copy._Name;
    this->_HitPoint = copy._HitPoint;
    this->_EnergyPoint = copy._EnergyPoint;    
    this->_Attack = copy._Attack;
    return (*this);
}

ClapTrap::~ClapTrap() { std::cout << "Destructed ClapTrap named " << _Name << std::endl; }

void ClapTrap::attack(const std::string& target) {
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

void ClapTrap::takeDamage(unsigned int amount) {

    if (_HitPoint > amount)
        _HitPoint -= amount;
    else if (_HitPoint < 0)
        _HitPoint = 0;
    else
        std::cout << _Name << " is already dead!" << std::endl;
    std::cout << "ClapTrap " << _Name << " takes " << amount << " damage" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount) {
    if (_EnergyPoint > 0 && _HitPoint)
    {
        _HitPoint += amount;
        std::cout << _Name << " repair " << amount << " worth of hitpoints" << std::endl;
        _EnergyPoint--;
    }
    else if (_EnergyPoint == 0)
        std::cout << "No energy to repair" << std::endl;
    else if (_HitPoint == 0)
        std::cout << "Already dead" << std::endl;
    else
        std::cout << "Hitpoints are at full amount" << std::endl;
}