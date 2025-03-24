/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nzharkev <nzharkev@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 13:43:13 by nzharkev          #+#    #+#             */
/*   Updated: 2025/03/24 09:56:49 by nzharkev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Zombie.hpp"

int main()
{
	{
		int size = 10;
		Zombie *horde1;
		horde1 = zombieHorde(size, "Walter");
		if (!horde1)
			return (1);
		for (int i = 0; i < size; i++)
			horde1[i].announce();
		delete [] horde1;
	}
	{
		int size = 10;
		Zombie *horde;
		horde = zombieHorde(size, "Patrick");
		if (!horde)
			return (1);
		for (int i = 0; i < size; i++)
			horde[i].announce();
		delete [] horde;

	}
	return (0);
}
