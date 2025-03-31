/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nzharkev <nzharkev@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-03-31 13:46:41 by nzharkev          #+#    #+#             */
/*   Updated: 2025-03-31 13:46:41 by nzharkev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ClapTrap.hpp"

int main()
{
    ClapTrap a("Chap");
    ClapTrap b("Chad");

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