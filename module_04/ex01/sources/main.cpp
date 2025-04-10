/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nzharkev <nzharkev@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 14:48:44 by nzharkev          #+#    #+#             */
/*   Updated: 2025/04/10 15:33:50 by nzharkev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Animal.hpp"
#include "../includes/Cat.hpp"
#include "../includes/Dog.hpp"
#include "../includes/WrongAnimal.hpp"
#include "../includes/WrongCat.hpp"

int main()
{
    {
        const Animal* j = new Dog();
        const Animal* i = new Cat();
        delete j;//should not create a leak
        delete i;
    }
    {
        int size = 6;
        Animal *pets[size];
        for (int i = 0; i < size; i++)
        {
            if (i < size / 2)
                pets[i] = new Dog();
            else
                pets[i] = new Cat();
        }
        for (int i = 0; i < size; i++)
            pets[i]->makeSound();
        std::cout << "Destructor:" << std::endl;
        for (int i = 0; i <  size; i++)
            delete pets[i];
    }
    std::cout << "\t**********************" << std::endl;
    {
        Dog a;
        Dog b(a);
        a.getBrain()->setIdea(0, "Play");
        a.getBrain()->setIdea(1, "Eat");
        a.getBrain()->setIdea(2, "Sleep");
        b.getBrain()->setIdea(0, "Eat");
        b.getBrain()->setIdea(1, "Sleep");
        b.getBrain()->setIdea(2, "Lay");
        for (int i = 0; i < 3; i++)
        {
            std::cout << "Idea " << i << ": " << a.getBrain()->getIdea(i) << std::endl;
            std::cout << "Idea " << i << ": " << b.getBrain()->getIdea(i) << std::endl;
        }
        std::cout << "Destructor:" << std::endl;
    }
    std::cout << "\t**********************" << std::endl;
    {
        Cat a;
        Cat b(a);
        a.getBrain()->setIdea(0, "Play");
        a.getBrain()->setIdea(1, "Eat");
        a.getBrain()->setIdea(2, "Sleep");
        b.getBrain()->setIdea(0, "Eat");
        b.getBrain()->setIdea(1, "Sleep");
        b.getBrain()->setIdea(2, "Lay");
        for (int i = 0; i < 3; i++)
        {
            std::cout << "Idea " << i << ": " << a.getBrain()->getIdea(i) << std::endl;
            std::cout << "Idea " << i << ": " << b.getBrain()->getIdea(i) << std::endl;
        }
        std::cout << "Destructor:" << std::endl;
    }
    std::cout << "\t**********************" << std::endl;
    return 0;  
}