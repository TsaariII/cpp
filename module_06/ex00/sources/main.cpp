/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nzharkev <nzharkev@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 10:22:59 by nzharkev          #+#    #+#             */
/*   Updated: 2025/07/02 12:34:41 by nzharkev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ScalarConventer.hpp"
#include <iostream>

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        if (argc == 1)
           std::cout << "What you think I can read mind?" << std::endl;
        else
            std::cout << "Only 1. Not 2 or 3 or whatever magic number you come up. One argument!" << std::endl;
        return 1;
    }
    std::string thing = argv[1];
    ScalarConverter::convert(thing);
}