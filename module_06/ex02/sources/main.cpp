/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nzharkev <nzharkev@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 14:15:10 by nzharkev          #+#    #+#             */
/*   Updated: 2025/07/02 14:42:15 by nzharkev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/A.hpp"
#include "../includes/B.hpp"
#include "../includes/C.hpp"
#include "../includes/Base.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

Base* generate()
{
    std::srand(std::time(nullptr));
    int g = std::rand() % 3;
    switch (g)
    {
        case 0: return new A;
        case 1: return new B;
        case 2: return new C;
        default: return nullptr;
    }
}

void identify(Base *ptr)
{
    if (dynamic_cast<A*>(ptr)) std::cout << "A" << std::endl;
    else if (dynamic_cast<B*>(ptr)) std::cout << "B" << std::endl;
    else if (dynamic_cast<C*>(ptr)) std::cout << "C" << std::endl;
    else std::cout << "Unknow type" << std::endl;
}

void identify(Base& ptr)
{
    try
    {
        A& a = dynamic_cast<A&>(ptr);
        (void)a;
        std::cout << "A" << std::endl;
        return;
    }
    catch(...) {}
    try
    {
        B& b = dynamic_cast<B&>(ptr);
        (void)b;
        std::cout << "B" << std::endl;
        return;
    }
    catch(...) {}
    try
    {
        C& c = dynamic_cast<C&>(ptr);
        (void)c;
        std::cout << "C" << std::endl;
        return;
    }
    catch(...) {}
    std::cout << "Unknow type" << std::endl;
}

int main()
{
    Base* object = generate();
    
    std::cout << "Pointer indentity: ";
    identify(object);
    std::cout << "Reference identity: ";
    identify(*object);
    delete object;
}