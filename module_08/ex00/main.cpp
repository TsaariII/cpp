/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nzharkev <nzharkev@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 16:05:28 by nzharkev          #+#    #+#             */
/*   Updated: 2025/07/03 16:15:49 by nzharkev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <vector>
#include <list>
#include <iostream>

int main()
{
    try
    {
        std::vector<int> ints = {1, 4, 7, 5, 8};
        auto it = easyfind(ints, 7);
        std::cout << "Found " << *it << std::endl;
        std::list<int> intList = {3, 5, 1, 2};
        auto it2 = easyfind(intList, 5);
        std::cout << "Found " << *it2 << std::endl;
        auto it3 = easyfind(intList, 9);
        std::cout << "Found " << *it3 << std::endl; 
    }
    catch (const std::exception &e)
    {   
        std::cerr << "Execption: " << e.what() << std::endl;
    }
    return 0;
}