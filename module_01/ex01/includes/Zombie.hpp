/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nzharkev <nzharkev@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 13:28:34 by nzharkev          #+#    #+#             */
/*   Updated: 2025/03/13 16:32:53 by nzharkev         ###   ########.fr       */
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
		Zombie();
		~Zombie();
		void announce();
		void zombieName(std::string name);
};

Zombie* zombieHorde( int N, std::string name );