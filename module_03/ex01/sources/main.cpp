/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nzharkev <nzharkev@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 13:46:41 by nzharkev          #+#    #+#             */
/*   Updated: 2025/04/02 14:41:11 by nzharkev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ScavTrap.hpp"

int main()
{
    ScavTrap a("Chap");
    ScavTrap b("Chad");

    a.attack("Chad");
    b.takeDamage(5);
    b.attack("Chap");
    a.takeDamage(3);
    
    b.beRepaired(5);
    a.attack("Chad");
    b.takeDamage(3);
    
    a.attack("Chad");
    b.takeDamage(5);
    b.attack("Chap");
    a.takeDamage(3);

    b.attack("Chap");
    a.takeDamage(3);
    a.attack("Chad");
    b.takeDamage(5);
    return 0;
}