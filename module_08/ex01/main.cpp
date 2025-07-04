/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nzharkev <nzharkev@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 17:33:18 by nzharkev          #+#    #+#             */
/*   Updated: 2025/07/04 13:06:01 by nzharkev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <vector>
#include <cstdlib>
#include <ctime>
#include <iostream>

int main()
{
    Span sp = Span(5);
    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);
    std::cout << sp.shortestSpan() << std::endl;
    std::cout << sp.longestSpan() << std::endl;

    try
    {
        std::cout << "\t======= BASIC TEST =======" << std::endl;
        std::srand(std::time(NULL));
        Span s(5);
        // for (size_t i = 0; i < 5; i++)
        //     s.addNumber(std::rand());
        s.addNumber(0);
        s.addNumber(4);
        s.addNumber(-3);
        std::cout << "Shortest span: " << s.shortestSpan() << std::endl;
        std::cout << "Longest span: " << s.longestSpan() << std::endl;
    }
    catch (std::exception& e)
    {
        std::cerr << "Exception (Basic Test): " << e.what() << std::endl;
    }
    try
    {
        std::cout << "\t======= ADDING TOO MANY TEST =======" << std::endl;
        Span s(2);
        s.addNumber(3);
        s.addNumber(5);
        s.addNumber(2);
    }
    catch (std::exception& e)
    {
        std::cerr << "Exception (Basic Test): " << e.what() << std::endl;
    }
    try
    {
        std::cout << "\t======= NOT ENOUGH ELEMENTS =======" << std::endl;
        Span s(2);
        s.addNumber(3);
        s.addNumber(5);
        std::cout << "Span size: 2" << std::endl;
        std::cout << "Shortest span: " << s.shortestSpan() << std::endl;
        std::cout << "Longest span: " << s.longestSpan() << std::endl;
    }
    catch (std::exception& e)
    {
        std::cerr << "Exception (Basic Test): " << e.what() << std::endl;
    }
    try
    {
        std::cout << "\t======= BIG TEST =======" << std::endl;
        std::vector<int> vec1(20000);
        std::generate(vec1.begin(), vec1.end(), std::rand);
        Span s(20000);
        s.addRange(vec1.begin(), vec1.end());
        std::cout << "Shortest span: " << s.shortestSpan() << std::endl;
        std::cout << "Longest span: " << s.longestSpan() << std::endl;
    }
    catch (std::exception& e)
    {
        std::cerr << "Exception (Basic Test): " << e.what() << std::endl;
    }
    return 0;
}
