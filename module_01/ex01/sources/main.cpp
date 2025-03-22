/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nzharkev <nzharkev@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 13:43:13 by nzharkev          #+#    #+#             */
/*   Updated: 2025/03/22 10:47:38 by nzharkev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Zombie.hpp"

int main()
{
	int size = 10;
	Zombie *horde;
	horde = zombieHorde(size, "Walter");
	if (!horde)
		return (1);
	for (int i = 0; i < size; i++)
		horde[i].announce();
	delete [] horde;
	return (0);
}
