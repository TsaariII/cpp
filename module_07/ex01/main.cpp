/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nzharkev <nzharkev@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 14:12:35 by nzharkev          #+#    #+#             */
/*   Updated: 2025/07/03 15:39:48 by nzharkev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"
#include <iostream>

template <typename T>
void print(const T& val)
{
    std::cout << val << std::endl;         
}

template <typename T>
void increment(T &x) { x++; }

int main()
{
    int intArray[5] = {1, 2, 3, 4, 5};
    std::string strArray[5] = {"aaa", "bbb", "CCCC",  "DDd", "EE"};
    double dblArray[5] = {6.7, 1.3, 2.4, 0.5, 0.02};
    
    std::cout << "intArray before increment:" << std::endl;
    iter(intArray, 5, print<int>);
    iter(intArray, 5, increment<int>);
    std::cout << "IntArray after increment:" << std::endl;
    iter(intArray, 5, print<int>);
    std::cout << "dblArray before increment:" << std::endl;
    iter(dblArray, 5, print<double>);
    iter(dblArray, 5, increment<double>);
    std::cout << "dblArray after increment:" << std::endl;
    iter(dblArray, 5, print<double>);
    std::cout << "strArray:" << std::endl;
    iter(strArray, 5, print<std::string>);
    return 0;
}