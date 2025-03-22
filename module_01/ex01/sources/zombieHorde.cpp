/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nzharkev <nzharkev@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 15:57:19 by nzharkev          #+#    #+#             */
/*   Updated: 2025/03/22 10:53:10 by nzharkev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Zombie.hpp"

Zombie* zombieHorde( int N, std::string name )
{
    try {
        Zombie *horde = new Zombie[N];
        for (int i = 0; i < N; i++)
            horde[i].zombieName(name);
        return (horde);
    }
    catch (const std::bad_alloc& e)
    {
        std::cerr << "The disease died out before it could create a horde." << std::endl;
        return nullptr;
    }
}
