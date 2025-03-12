/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nzharkev <nzharkev@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 13:28:34 by nzharkev          #+#    #+#             */
/*   Updated: 2025/03/12 13:59:32 by nzharkev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>


class Zombie
{
	private:
		std::string _Name;
	public:
		Zombie(std::string name);
		~Zombie();
		void announce();
};

Zombie *newZombie(std::string new_name);
void randomChump(std::string name);
