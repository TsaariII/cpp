/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nzharkev <nzharkev@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 13:46:41 by nzharkev          #+#    #+#             */
/*   Updated: 2025/04/03 12:35:29 by nzharkev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ScavTrap.hpp"

void basicTests()
{
    std::cout << "\n\t|==== BASIC TESTS ====|" << std::endl;
    std::cout << "This is default constructor A:" << std::endl;
    ScavTrap a;
    std::cout << "This is constructor B:" << std::endl;
    ScavTrap b("Guy");
    std::cout << "This is copy of A. C:" << std::endl;
    ScavTrap c(a);
    std::cout << "This is copy assignment of B. D:" << std::endl;
    ScavTrap d;
    d = b;
    std::cout << "Taking the special action:" << std::endl;
    std::cout << "A: ";
    a.guardGate();
    std::cout << "B: ";
    b.guardGate();
    std::cout << "C: ";
    c.guardGate();
    std::cout << "D: ";
    d.guardGate();
    std::cout << "Taking the special action again:" << std::endl;
    std::cout << "A: ";
    a.guardGate();
    std::cout << "B: ";
    b.guardGate();
    std::cout << "C: ";
    c.guardGate();
    std::cout << "D: ";
    d.guardGate();
    std::cout << "Healing if healt is full:" << std::endl;
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
    a.takeDamage(20);
    std::cout << "B: ";
    b.takeDamage(20);
    std::cout << "C: ";
    c.takeDamage(20);
    std::cout << "D: ";
    d.takeDamage(20);
    std::cout << "This is the repair:" << std::endl;
    std::cout << "A: ";
    a.beRepaired(10);
    std::cout << "B: ";
    b.beRepaired(10);
    std::cout << "C: ";
    c.beRepaired(10);
    std::cout << "D: ";
    d.beRepaired(10);
}

void testsWhenDead()
{
    std::cout << "\n\t|==== TESTS WHEN DEAD ====|" << std::endl;
    std::cout << "This is default constructor A:" << std::endl;
    ScavTrap a;
    std::cout << "This is constructor B:" << std::endl;
    ScavTrap b("Guy");
    std::cout << "This is copy of A. C:" << std::endl;
    ScavTrap c(a);
    std::cout << "This is copy assignment of B. D:" << std::endl;
    ScavTrap d;
    d = b;
    std::cout << "This is slaughter:" << std::endl;
    std::cout << "A: ";
    a.takeDamage(101);
    std::cout << "B: ";
    b.takeDamage(101);
    std::cout << "C: ";
    c.takeDamage(101);
    std::cout << "D: ";
    d.takeDamage(101);
    std::cout << "Trying to do actions when dead:" << std::endl;
    std::cout << "A: ";
    a.beRepaired(5);
    std::cout << "A: ";
    a.attack("Guy");
    std::cout << "A: ";
    a.guardGate();
    std::cout << "B: ";
    b.beRepaired(5);
    std::cout << "B: ";
    b.attack("Name");
    std::cout << "B: ";
    b.guardGate();
    std::cout << "C: ";
    c.beRepaired(5);
    std::cout << "C: ";
    c.attack("Guy");
    std::cout << "C: ";
    c.guardGate();
    std::cout << "D: ";
    d.beRepaired(5);
    std::cout << "D: ";
    d.attack("Guy");
    std::cout << "D: ";
    d.guardGate();
}

void testsZeroEnergy()
{
    std::cout << "\n\t|==== TESTS WHEN ZERO ENERGY ====|" << std::endl; 
    std::cout << "This is default constructor A:" << std::endl;
    ScavTrap a;
    std::cout << "This is constructor B:" << std::endl;
    ScavTrap b("Guy");
    std::cout << "This is copy of A. C:" << std::endl;
    ScavTrap c(a);
    std::cout << "This is copy assignment of B. D:" << std::endl;
    ScavTrap d;
    d = b;
    std::cout << "The attack until there is no energy left:" << std::endl;
    for(int i = 0; i <= 50; i++)
    {
        std::cout << "Energy: " << (50 - i) << std::endl;
        std::cout << "A: ";
        a.attack("Guy");
        std::cout << "B: ";
        b.attack("Name");
        std::cout << "C: ";
        c.attack("Guy");
        std::cout << "D: ";
        d.attack("Guy");
    }
    std::cout << "Taking the special action:" << std::endl;
    std::cout << "A: ";
    a.guardGate();
    std::cout << "B: ";
    b.guardGate();
    std::cout << "C: ";
    c.guardGate();
    std::cout << "D: ";
    d.guardGate();
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
    basicTests();
    // testsWhenDead();
    // testsZeroEnergy();
    return 0;
}