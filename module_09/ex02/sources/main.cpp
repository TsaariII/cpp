/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nzharkev <nzharkev@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 10:39:49 by nzharkev          #+#    #+#             */
/*   Updated: 2025/07/23 15:33:44 by nzharkev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/PmergeMe.hpp"
#include <iostream>

int main(int argc, char **argv)
{
    if (argc < 2)
    {
        std::cerr << "Error" << std::endl;
        return 1;
    }
    try
    {
        PmergeMe fj;
        fj.readInput(argv + 1);
        fj.sorter();
    }
    catch(const std::exception& e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }
    return 0;
}