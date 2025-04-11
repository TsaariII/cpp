/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nzharkev <nzharkev@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 12:24:46 by nzharkev          #+#    #+#             */
/*   Updated: 2025/04/10 15:52:28 by nzharkev         ###   ########.fr       */
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
        std::cout << "\tMY TESTS" << std::endl;
        std::cout << "Hero created" << std::endl;
        Character *a = new Character("Hero");
        std::cout << "Creating materia pool" << std::endl;
        MateriaSource* src = new MateriaSource();
        std::cout << "Creating cure materia" << std::endl;
        src->learnMateria(new Cure());
        std::cout << "Added Ice materia" << std::endl;
        src->learnMateria(new Ice());
        std::cout << "Add cure to materia pool" << std::endl;
        AMateria *ice = src->createMateria("ice");
        std::cout << "Add cure to materia pool" << std::endl;
        AMateria *cure = src->createMateria("cure");
        std::cout << "Hero equipped ice" << std::endl;
        a->equip(ice);
        std::cout << "Hero equipped cure" << std::endl;
        a->equip(cure);
        AMateria *floor[100];
        std::cout << "Hero unequipped cure" << std::endl;
        floor[0] = cure;
        a->unequip(1);
        std::cout << "Created target for Hero named BOB" << std::endl;
        ICharacter* bob = new Character("BOB");
        std::cout << "Hero uses ice" << std::endl;
        a->use(0, *bob);
        std::cout << "Hero forgot that he has cure and tried use it" << std::endl;
        a->use(1, *bob);
        std::cout << "GAME OVER" << std::endl;
        delete a;
        delete bob;
        delete src;
        delete floor[0];
    }
    return 0;
}