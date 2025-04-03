/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nzharkev <nzharkev@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 13:46:41 by nzharkev          #+#    #+#             */
/*   Updated: 2025/04/03 12:59:39 by nzharkev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/FragTrap.hpp"

int main()
{
    {
        std::cout << "\t|==== BASIC TESTS ====|" << std::endl;
        std::cout << "This is default:" << std::endl;
        FragTrap a;
        std::cout << "This is constructor:" << std::endl;
        FragTrap b("Guy");
        std::cout << "This is copy:" << std::endl;
        FragTrap c(a);
        FragTrap d;
        std::cout << "This is assignment:" << std::endl;
        d = b;
        std::cout << "Taking the special action:" << std::endl;
        a.highFivesGuys();
        b.highFivesGuys();
        c.highFivesGuys();
        d.highFivesGuys();
        std::cout << "Taking the special action again:" << std::endl;
        a.highFivesGuys();
        b.highFivesGuys();
        c.highFivesGuys();
        d.highFivesGuys();
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
        a.takeDamage(20);
        b.takeDamage(20);
        c.takeDamage(20);
        d.takeDamage(20);
        std::cout << "This is the repair(or heal?):" << std::endl;
        a.beRepaired(10);
        b.beRepaired(10);
        c.beRepaired(10);
        d.beRepaired(10);
    }
    {
        std::cout << "\t|==== TESTS WHEN DEAD ====|" << std::endl;
        std::cout << "This is default:" << std::endl;
        FragTrap a;
        std::cout << "This is constructor:" << std::endl;
        FragTrap b("Guy");
        std::cout << "This is copy:" << std::endl;
        FragTrap c(a);
        FragTrap d;
        std::cout << "This is slaughter:" << std::endl;
        a.takeDamage(101);
        b.takeDamage(101);
        c.takeDamage(101);
        d.takeDamage(101);
        std::cout << "Trying to do actions when dead:" << std::endl;
        a.beRepaired(5);
        a.attack("Guy");
        a.highFivesGuys();
        b.beRepaired(5);
        b.attack("Name");
        b.highFivesGuys();
        c.beRepaired(5);
        c.attack("Guy");
        c.highFivesGuys();
        d.beRepaired(5);
        d.attack("Guy");
        d.highFivesGuys();
    }
    {
        std::cout << "\t|==== TESTS WHEN ZERO ENERGY ====|" << std::endl; 
        std::cout << "This is default:" << std::endl;
        FragTrap a;
        std::cout << "This is constructor:" << std::endl;
        FragTrap b("Guy");
        std::cout << "This is copy:" << std::endl;
        FragTrap c(a);
        FragTrap d;
        std::cout << "This is assignment:" << std::endl;
        d = b;
        std::cout << "The attack until there is no energy left:" << std::endl;
        for(int i = 0; i < 51; i++)
        {
            a.attack("Guy");
            b.attack("Name");
            c.attack("Guy");
            d.attack("Guy");
            if (50 - (i + 1) < 0)
                break ;
            std::cout << "Energy: " << (50 - (i + 1)) << std::endl;
        }
        std::cout << "Taking the special action:" << std::endl;
        a.highFivesGuys();
        b.highFivesGuys();
        c.highFivesGuys();
        d.highFivesGuys();
        std::cout << "This is the repair(or heal?):" << std::endl;
        a.beRepaired(10);
        b.beRepaired(10);
        c.beRepaired(10);
        d.beRepaired(10);
    }
    return 0;
}