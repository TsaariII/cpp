/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nzharkev <nzharkev@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 16:59:21 by nzharkev          #+#    #+#             */
/*   Updated: 2025/03/13 17:51:28 by nzharkev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Weapon.hpp"

Weapon::Weapon(std::string weapon) : _Type(weapon) {}
Weapon::~Weapon() {};
const std::string& Weapon::getType() const { return _Type; };
void Weapon::setType(std::string type) { _Type = type; };