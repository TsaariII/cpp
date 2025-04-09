/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nzharkev <nzharkev@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-04-08 12:24:46 by nzharkev          #+#    #+#             */
/*   Updated: 2025-04-08 12:24:46 by nzharkev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Character.hpp"
#include "../includes/Cure.hpp"
#include "../includes/Ice.hpp"
#include "../includes/MateriaSource.hpp"

int main()
{
    {
        IMateriaSource* src = new MateriaSource();
        src->learnMateria(new Cure());
        src->learnMateria(new Ice());
        ICharacter* me = new Character("me");
        AMateria* tmp;
        tmp = src->createMateria("ice");
        me->equip(tmp);
        tmp = src->createMateria("cure");
        me->equip(tmp);
        ICharacter* bob = new Character("bob");
        me->use(0, *bob);
        me->use(1, *bob);
        delete bob;
        delete me;
        delete src;
    }
    {
        Character *a = new Character("Hero");
        MateriaSource* src = new MateriaSource();
        src->learnMateria(new Cure());
        src->learnMateria(new Ice());
        AMateria *ice = src->createMateria("ice");
        AMateria *cure = src->createMateria("cure");
        a->equip(ice);
        a->equip(cure);
        AMateria *floor[100];
        floor[0] = ice;
        a->unequip(0);
        delete a;
        delete src;
        delete floor[0];
    }
    return 0;
}