/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nzharkev <nzharkev@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 13:38:33 by nzharkev          #+#    #+#             */
/*   Updated: 2025/07/02 13:46:10 by nzharkev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include <iostream>
#include <cstdlib>

int main()
{
    Data d1;
    d1.id = 25;
    d1.name = "Will";

    uintptr_t raw = Serializer::serializer(&d1);
    Data *copy = Serializer::deserialize(raw);
    
    std::cout << "D1 address: " << &d1 << "\n";
    std::cout << "Copy addres: " << copy << "\n";
    std::cout << std::boolalpha<< (&d1 == copy) << "\n";
    std::cout << "Copy contents id=" << copy->id << ", name=" << copy->name << std::endl;
}