/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nzharkev <nzharkev@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 11:25:56 by nzharkev          #+#    #+#             */
/*   Updated: 2025/03/14 11:29:07 by nzharkev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/HumanA.hpp"
#include <iostream>

HumanA::HumanA(std::string name, Weapon weapon) : _Name(name), _Weapon(weapon) {};
HumanA::~HumanA() {};
void HumanA::attack() { std::cout << _Name << " attacks with their " << _Weapon.getType() << std::endl; };

