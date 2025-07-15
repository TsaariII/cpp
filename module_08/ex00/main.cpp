/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nzharkev <nzharkev@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 16:05:28 by nzharkev          #+#    #+#             */
/*   Updated: 2025/07/15 11:15:11 by nzharkev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <set>
#include "easyfind.hpp"

template <typename T>
void tester(const std::string& contName, T container, int value) {
    std::cout << "Testing value " << value << " in container " << contName << ": ";
    for (typename T::iterator it = container.begin(); it != container.end(); ++it)
        std::cout << *it << " ";
    std::cout << std::endl;

    try {
        typename T::iterator result = easyfind(container, value);
        std::cout << "Found value: " << *result << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }
}

int main() {
    std::vector<int> v = {10, 20, 30, 40, 50};
    std::list<int> l = {1, 2, 3, 4, 5};
    std::deque<int> d = {100, 200, 300};
    std::set<int> s = {7, 14, 21};

    tester("std::vector", v, 30);
    tester("std::vector", v, 99);
    tester("std::list", l, 3);
    tester("std::list", l, 6);
    tester("std::deque", d, 100);
    tester("std::deque", d, 301);
    tester("std::set", s, 14);
    tester("std::set", s, 100);

    std::vector<int> empty;
    tester("", empty, 5);

    std::vector<int> one = {42};
    tester("std::vector", one, 42);
    tester("std::vector", one, 1);
}