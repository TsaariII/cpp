/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nzharkev <nzharkev@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-03-31 14:13:00 by nzharkev          #+#    #+#             */
/*   Updated: 2025-03-31 14:13:00 by nzharkev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap("Default")
{
    _HitPoint = 100;
    _EnergyPoint = 50;
    _Attack = 20;
}

ScavTrap::ScavTrap(std::string name) {}

ScavTrap::ScavTrap(const ScavTrap &copy) {}

ScavTrap& ScavTrap::operator=(const ScavTrap &copy) {}

ScavTrap::~ScavTrap() {}

void ScavTrap::attack(const std::string &target) {}

void ScavTrap::guardGate() {}