/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nzharkev <nzharkev@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 17:33:18 by nzharkev          #+#    #+#             */
/*   Updated: 2025/07/15 10:57:18 by nzharkev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include "Span.hpp"

void test_basic_spans() {
    std::cout << "\n=== Basic Span Tests ===" << std::endl;
    Span sp(5);
    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);

    std::cout << "Shortest: " << sp.shortestSpan() << std::endl;  // Should be 2
    std::cout << "Longest: " << sp.longestSpan() << std::endl;    // Should be 14
}

void test_overflow() {
    std::cout << "\n=== Test Overflow Exception ===" << std::endl;
    Span sp(2);
    sp.addNumber(1);
    sp.addNumber(2);
    try {
        sp.addNumber(3);  // Should throw
    } catch (const std::exception& e) {
        std::cout << "Caught exception: " << e.what() << std::endl;
    }
}

void test_not_enough_elements() {
    std::cout << "\n=== Not Enough Elements Exception ===" << std::endl;
    Span sp(2);
    sp.addNumber(1);
    try {
        sp.shortestSpan();  // Should throw
    } catch (const std::exception& e) {
        std::cout << "Caught exception: " << e.what() << std::endl;
    }
}

void test_negative_numbers() {
    std::cout << "\n=== Negative Number Handling ===" << std::endl;
    Span sp(4);
    sp.addNumber(-10);
    sp.addNumber(0);
    sp.addNumber(10);
    sp.addNumber(100);
    std::cout << "Shortest: " << sp.shortestSpan() << std::endl;  // 10
    std::cout << "Longest: " << sp.longestSpan() << std::endl;   // 110
}

void test_identical_numbers() {
    std::cout << "\n=== Identical Numbers ===" << std::endl;
    Span sp(3);
    sp.addNumber(42);
    sp.addNumber(42);
    sp.addNumber(42);
    std::cout << "Shortest: " << sp.shortestSpan() << std::endl;  // 0
    std::cout << "Longest: " << sp.longestSpan() << std::endl;    // 0
}

void test_large_random() {
    std::cout << "\n=== Large Random Data (10000) ===" << std::endl;
    Span sp(10000);
    std::vector<int> data(10000);
    std::generate(data.begin(), data.end(), std::rand);
    sp.addRange(data.begin(), data.end());
    std::cout << "Shortest: " << sp.shortestSpan() << std::endl;
    std::cout << "Longest: " << sp.longestSpan() << std::endl;
}

void test_edge_addRange() {
    std::cout << "\n=== addRange() Capacity Overflow ===" << std::endl;
    Span sp(5);
    std::vector<int> more = {1, 2, 3, 4, 5, 6};
    try {
        sp.addRange(more.begin(), more.end());  // should throw
    } catch (const std::exception& e) {
        std::cout << "Caught exception: " << e.what() << std::endl;
    }
}

int main() {
    std::srand(std::time(NULL));
    test_basic_spans();
    test_overflow();
    test_not_enough_elements();
    test_negative_numbers();
    test_identical_numbers();
    test_large_random();
    test_edge_addRange();
    return 0;
}
