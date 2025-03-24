/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nzharkev <nzharkev@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 11:34:08 by nzharkev          #+#    #+#             */
/*   Updated: 2025/03/24 10:30:54 by nzharkev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/HumanB.hpp"
#include <iostream>

HumanB::HumanB(std::string name) : _Name(name) {};
HumanB::~HumanB() {};
void HumanB::setWeapon(Weapon &weapon) { _Weapon = &weapon; };
void HumanB::attack() { std::cout << _Name << " attacks with their " << _Weapon->getType() << std::endl; };
