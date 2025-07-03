/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nzharkev <nzharkev@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 15:20:56 by nzharkev          #+#    #+#             */
/*   Updated: 2025/07/03 15:39:38 by nzharkev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"
#include <iostream>

int main()
{
    try
    {
        Array<int> intArray(5);
        for (size_t i = 0; i < intArray.size(); i++)
            intArray[i] = i * 10;
        std::cout << "intArray:\n";
        for (size_t i = 0; i < intArray.size(); i++)
            std::cout << intArray[i] << " ";
        std::cout << std::endl;
        Array<int> copyArray(intArray);
        std::cout << "copyArray:\n";
        for (size_t i = 0; i < copyArray.size(); i++)
            std::cout << copyArray[i] << " ";
        std::cout << std::endl;
        Array<int> eqArray = intArray;
        std::cout << "eqArray:\n";
        for (size_t i = 0; i < eqArray.size(); i++)
            std::cout << eqArray[i] << " ";
        std::cout << std::endl;
        copyArray[0] = 1000;
        eqArray[0] = 999;
        std::cout << "Proof that the copies are deep\ncopyArray[0] = " << copyArray[0] << " eqArray[0] = " << eqArray[0] << " intArray[0] = " << intArray[0] << std::endl;
        std::cout << "Accessing out of bounds element:" << std::endl;
        intArray[6];
    }
    catch(const std::exception& e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
    return 0;
}