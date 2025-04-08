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

void basicTests()
{
    std::cout << "\n\t|==== BASIC TESTS ====|" << std::endl;
    std::cout << "This is default constructor A:" << std::endl;
    ClapTrap a;
    std::cout << "This is constructor B:" << std::endl;
    ClapTrap b("Guy");
    std::cout << "This is copy of A. C:" << std::endl;
    ClapTrap c(a);
    std::cout << "This is copy assignment of B. D:" << std::endl;
    ClapTrap d;
    d = b;
    std::cout << "Repairing if healt is full:" << std::endl;
    std::cout << "A: ";
    a.beRepaired(1);
    std::cout << "B: ";
    b.beRepaired(1);
    std::cout << "C: ";
    c.beRepaired(1);
    std::cout << "D: ";
    d.beRepaired(1);
    std::cout << "Here is the attack:" << std::endl;
    std::cout << "A: ";
    a.attack("Guy");
    std::cout << "B: ";
    b.attack("Name");
    std::cout << "C: ";
    c.attack("Guy");
    std::cout << "D: ";
    d.attack("Guy");
    std::cout << "Now they take damage:" << std::endl;
    std::cout << "A: ";
    a.takeDamage(5);
    std::cout << "B: ";
    b.takeDamage(5);
    std::cout << "C: ";
    c.takeDamage(5);
    std::cout << "D: ";
    d.takeDamage(5);
    std::cout << "This is the repair:" << std::endl;
    std::cout << "A: ";
    a.beRepaired(3);
    std::cout << "B: ";
    b.beRepaired(3);
    std::cout << "C: ";
    c.beRepaired(3);
    std::cout << "D: ";
    d.beRepaired(3);
}

void testsWhenDead()
{
    std::cout << "\n\t|==== TESTS WHEN DEAD ====|" << std::endl;
    std::cout << "This is default constructor A:" << std::endl;
    ClapTrap a;
    std::cout << "This is constructor B:" << std::endl;
    ClapTrap b("Guy");
    std::cout << "This is copy of A. C:" << std::endl;
    ClapTrap c(a);
    std::cout << "This is copy assignment of B. D:" << std::endl;
    ClapTrap d;
    d = b;
    std::cout << "This is slaughter:" << std::endl;
    std::cout << "A: ";
    a.takeDamage(10);
    std::cout << "B: ";
    b.takeDamage(10);
    std::cout << "C: ";
    c.takeDamage(10);
    std::cout << "D: ";
    d.takeDamage(10);
    std::cout << "Trying to do actions when dead:" << std::endl;
    std::cout << "A: ";
    a.beRepaired(5);
    std::cout << "A: ";
    a.attack("Guy");
    std::cout << "B: ";
    b.beRepaired(5);
    std::cout << "B: ";
    b.attack("Name");
    std::cout << "C: ";
    c.beRepaired(5);
    std::cout << "C: ";
    c.attack("Guy");
    std::cout << "D: ";
    d.beRepaired(5);
    std::cout << "D: ";
    d.attack("Guy");
    std::cout << "Taking damage when dead:" << std::endl;
    std::cout << "A: ";
    a.takeDamage(5);
    std::cout << "B: ";
    b.takeDamage(5);
    std::cout << "C: ";
    c.takeDamage(5);
    std::cout << "D: ";
    d.takeDamage(5);
}

void testsZeroEnergy()
{
    std::cout << "\n\t|==== TESTS WHEN ZERO ENERGY ====|" << std::endl; 
    std::cout << "This is default constructor A:" << std::endl;
    ClapTrap a;
    std::cout << "This is constructor B:" << std::endl;
    ClapTrap b("Guy");
    std::cout << "This is copy of A. C:" << std::endl;
    ClapTrap c(a);
    std::cout << "This is copy assignment of B. D:" << std::endl;
    ClapTrap d;
    d = b;
    std::cout << "The attack until there is no energy left:" << std::endl;
    for(int i = 0; i <= 10; i++)
    {
        std::cout << "Energy: " << (10 - i) << std::endl;
        std::cout << "A: ";
        a.attack("Guy");
        std::cout << "B: ";
        b.attack("Name");
        std::cout << "C: ";
        c.attack("Guy");
        std::cout << "D: ";
        d.attack("Guy");  
    }
    std::cout << "Repairing when energy zero:" << std::endl;
    std::cout << "A: ";
    a.beRepaired(10);
    std::cout << "B: ";
    b.beRepaired(10);
    std::cout << "C: ";
    c.beRepaired(10);
    std::cout << "D: ";
    d.beRepaired(10);
}

int main()
{
    // basicTests();
    testsWhenDead();
    // testsZeroEnergy();
    return 0;
}