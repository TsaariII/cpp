/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nzharkev <nzharkev@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 13:34:21 by nzharkev          #+#    #+#             */
/*   Updated: 2025/03/13 16:34:05 by nzharkev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Zombie.hpp"

Zombie::Zombie(std::string name) : _Name(name) {}

Zombie::Zombie() {};

Zombie::~Zombie() { std::cout << "We lost zombie named " << _Name << std::endl; };

void Zombie::announce() {std::cout << _Name << ": BraiiiiiiinnnzzzZ..." << std::endl; };

void Zombie::zombieName(std::string name) { _Name = name; };