/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nzharkev <nzharkev@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 10:00:57 by nzharkev          #+#    #+#             */
/*   Updated: 2025/04/03 14:02:22 by nzharkev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ClapTrap.hpp"

ClapTrap::ClapTrap() : _Name("Cname"), _HitPoint(100), _EnergyPoint(50), _Attack(30) {
    std::cout << "\033[34mConstructed default ClapTrap named " << _Name << "\033[0m" << std::endl;
}

ClapTrap::ClapTrap(std::string name) : _Name(name), _HitPoint(100), _EnergyPoint(50), _Attack(20) {
    std::cout << "\033[36mConstructed ClapTrap named " << _Name << "\033[0m" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &copy) : _Name(copy._Name), _HitPoint(copy._HitPoint), _EnergyPoint(copy._EnergyPoint), _Attack(copy._Attack) {
    std::cout << "\033[94mConstructed copy Claptrap named " << _Name << "\033[0m" << std::endl; 
}

ClapTrap& ClapTrap::operator=(const ClapTrap &copy) {
    std::cout << "\033[33mAssignment operator called\033[0m" << std::endl;
    if (this != &copy)
    {
        this->_Name = copy._Name;
        this->_HitPoint = copy._HitPoint;
        this->_EnergyPoint = copy._EnergyPoint;    
        this->_Attack = copy._Attack;
    }
    return (*this);
}

ClapTrap::~ClapTrap() { std::cout << "\033[31mDestructed ClapTrap named " << _Name << "\033[0m" << std::endl; }

void ClapTrap::attack(const std::string& target) {
    if (_HitPoint > 0 && _EnergyPoint > 0)
    {
        std::cout << "\033[4;96mClapTrap " << _Name << " attacks " <<  target
                << ", causing " << _Attack << " points of damage!\033[0m"
                << std::endl;
        _EnergyPoint--;
    }
    else if (_EnergyPoint == 0)
        std::cout << "\033[1;96;41mClapTrap " << _Name << " has no energy to attack!\033[0m" << std::endl;
    else
        std::cout << "ClapTrap " << _Name << " could't attack!" << std::endl; 
}

void ClapTrap::takeDamage(unsigned int amount) {

    if (_HitPoint == 0)
    {
        std::cout << "\033[30mClapTrap " << _Name << " is already dead!\033[0m" << std::endl;
        return ;
    }
    else
    {
        _HitPoint -= amount;
        if (_HitPoint < 0)
        {
            std::cout << "\033[30mClapTrap " << _Name << " is dead\033[0m" << std::endl;
            _HitPoint = 0;
            return ;
        }
        std::cout << "\033[4;90mClapTrap " << _Name << " takes " << amount << " damage\033[0m" << std::endl;
    }
}

void ClapTrap::beRepaired(unsigned int amount) {
    if (_EnergyPoint == 0)
        std::cout << "\033[33mNo energy to repair\033[0m" << std::endl;
    else if (_HitPoint == 100)
    {
        std::cout << "\033[90;42mHitpoints are at full amount\033[0m" << std::endl;
        return ;
    }
    if (_EnergyPoint > 0 && _HitPoint > 0)
    {
        _HitPoint += amount;
        std::cout << "\033[1;97;41mClapTrap " << _Name << " repairs " << amount << " worth of hitpoints\033[0m" << std::endl;
        _EnergyPoint--;
    }
    else if (_HitPoint == 0)
        std::cout << "\033[30mClapTrap" << _Name << " is already dead!\033[0m" << std::endl;
}