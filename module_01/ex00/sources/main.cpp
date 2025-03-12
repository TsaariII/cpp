/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nzharkev <nzharkev@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 13:43:13 by nzharkev          #+#    #+#             */
/*   Updated: 2025/03/12 14:21:25 by nzharkev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Zombie.hpp"

int main()
{
	Zombie zomb1("Rex");
	zomb1.announce();
	randomChump("Big Ben");
	Zombie *zombieptr = newZombie("Carl");
	zombieptr->announce();
	delete zombieptr;
	return (0);
}
