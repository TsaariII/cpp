/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nzharkev <nzharkev@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 14:48:44 by nzharkev          #+#    #+#             */
/*   Updated: 2025/04/03 16:37:00 by nzharkev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Animal.hpp"
#include "../includes/Cat.hpp"
#include "../includes/Dog.hpp"


int main()
{
    // {
    //     const Animal* meta = new Animal();
    //     const Animal* j = new Dog();
    //     const Animal* i = new Cat();
    //     std::cout << j->getType() << " " << std::endl;
    //     std::cout << i->getType() << " " << std::endl;
    //     i->makeSound();
    //     j->makeSound();
    //     meta->makeSound();
    
    //     delete meta;    
    //     delete i;
    //     delete j;
    // }
    {
        const Animal *a = new Animal();
        const Animal *b = new Cat();
        const Animal *c = new Dog();
        const Animal *d(c);
        std::cout << a->getType() << " " << std::endl;
        std::cout << b->getType() << " " << std::endl;
        std::cout << c->getType() << " " << std::endl;
        std::cout << d->getType() << " " << std::endl;
        delete a;
        delete b;
        delete c;
        delete d;
    }
    return 0;  
}