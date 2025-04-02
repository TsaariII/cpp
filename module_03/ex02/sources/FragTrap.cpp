/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nzharkev <nzharkev@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 20:23:54 by nzharkev          #+#    #+#             */
/*   Updated: 2025/04/02 20:39:31 by nzharkev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap("Default")
{ 
    std::cout << "Constructed default FragTrap named " << _Name << std::endl;
}
FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
    std::cout << "Constructed FragTrap named " << _Name << std::endl;
}
FragTrap::FragTrap(const FragTrap &copy) {}
FragTrap& FragTrap::operator=(const FragTrap &copy) {}
FragTrap::~FragTrap() {}
void FragTrap::attack(const std::string &target) {}
void FragTrap::highFivesGuys(void) {}