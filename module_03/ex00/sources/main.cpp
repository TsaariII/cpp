/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nzharkev <nzharkev@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 13:46:41 by nzharkev          #+#    #+#             */
/*   Updated: 2025/04/03 11:31:40 by nzharkev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ClapTrap.hpp"

int main()
{
    {
        std::cout << "This is default:" << std::endl;
        ClapTrap a;
        std::cout << "This is constructor:" << std::endl;
        ClapTrap b("Guy");
        std::cout << "This is copy:" << std::endl;
        ClapTrap c(a);
        ClapTrap d;
        std::cout << "This is assignment:" << std::endl;
        d = b;
        std::cout << "Healing if healt is full:" << std::endl;
        a.beRepaired(1);
        b.beRepaired(1);
        c.beRepaired(1);
        d.beRepaired(1);
        std::cout << "Here is the attack:" << std::endl;
        a.attack("Guy");
        b.attack("Name");
        c.attack("Guy");
        d.attack("Guy");
        std::cout << "Now they take damage:" << std::endl;
        a.takeDamage(5);
        b.takeDamage(5);
        c.takeDamage(5);
        d.takeDamage(5);
        std::cout << "This is the repair(or heal?):" << std::endl;
        a.beRepaired(3);
        b.beRepaired(3);
        c.beRepaired(3);
        d.beRepaired(3);
        std::cout << "This is slaughter:" << std::endl;
        a.takeDamage(10);
        b.takeDamage(10);
        c.takeDamage(10);
        d.takeDamage(10);
        std::cout << "Trying to do actions when dead:" << std::endl;
        a.beRepaired(5);
        a.attack("Guy");
        b.beRepaired(5);
        b.attack("Name");
        c.beRepaired(5);
        c.attack("Guy");
        d.beRepaired(5);
        d.attack("Guy");
    }
    {
        std::cout << "This is default:" << std::endl;
        ClapTrap a;
        std::cout << "This is constructor:" << std::endl;
        ClapTrap b("Guy");
        std::cout << "This is copy:" << std::endl;
        ClapTrap c(a);
        ClapTrap d;
        std::cout << "This is assignment:" << std::endl;
        d = b;
        std::cout << "The attack until there is no energy left:" << std::endl;
        for(int i = 0; i < 11; i++)
        {
            a.attack("Guy");
            b.attack("Name");
            c.attack("Guy");
            d.attack("Guy");  
        }
    }
    return 0;
}