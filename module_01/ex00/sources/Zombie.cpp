/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nzharkev <nzharkev@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 13:34:21 by nzharkev          #+#    #+#             */
/*   Updated: 2025/03/13 15:51:42 by nzharkev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Zombie.hpp"

Zombie::Zombie(std::string name) : _Name(name) {}

Zombie::~Zombie() { std::cout << "We lost zombie named " << _Name << std::endl; };

void Zombie::announce() {std::cout << _Name << ": BraiiiiiiinnnzzzZ..." << std::endl; };
