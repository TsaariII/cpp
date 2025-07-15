/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nzharkev <nzharkev@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 13:34:46 by nzharkev          #+#    #+#             */
/*   Updated: 2025/07/15 11:42:53 by nzharkev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "MutantStack.hpp"
#include <list>
#include <string>

void test_basic_operations()
{
    std::cout << "\n=== Basic Stack Operations ===" << std::endl;
    MutantStack<int> mstack;
    mstack.push(10);
    mstack.push(20);
    mstack.push(30);
    std::cout << "mstack[" <<mstack.size() << "]:";
    for (MutantStack<int>::iterator it = mstack.begin(); it != mstack.end(); ++it)
        std::cout << " " << *it;
    std::cout << std::endl;
    std::cout << "Top: " << mstack.top() << std::endl;
    mstack.pop();
    std::cout << "After pop, top: " << mstack.top() << std::endl;
    std::cout << "Size: " << mstack.size() << std::endl;
    std::cout << "Is empty: " << std::boolalpha << mstack.empty() << std::endl;
}

void test_iteration()
{
    std::cout << "\n=== Forward Iteration ===" << std::endl;
    MutantStack<int> mstack;
    for (int i = 1; i <= 5; ++i)
        mstack.push(i * 10);
    std::cout << std::endl;
    for (MutantStack<int>::iterator it = mstack.begin(); it != mstack.end(); ++it)
        std::cout << *it << " ";
    std::cout << std::endl;
}

void test_reverse_iteration()
{
    std::cout << "\n=== Reverse Iteration ===" << std::endl;
    MutantStack<int> mstack;
    for (int i = 1; i <= 5; ++i)
        mstack.push(i * 10);
    for (MutantStack<int>::reverse_iterator rit = mstack.rbegin(); rit != mstack.rend(); ++rit)
        std::cout << *rit << " ";
    std::cout << std::endl;
}

void test_const_iteration()
{
    std::cout << "\n=== Const Iteration ===" << std::endl;
    MutantStack<int> mstack;
    for (int i = 0; i < 5; ++i)
        mstack.push(i + 1);
    const MutantStack<int> cmstack = mstack;
    for (MutantStack<int>::const_iterator it = cmstack.begin(); it != cmstack.end(); ++it)
        std::cout << *it << " ";
    std::cout << std::endl;
}

void test_copy_constructor_and_assignment()
{
    std::cout << "\n=== Copy Constructor and Assignment ===" << std::endl;
    MutantStack<int> original;
    original.push(1);
    original.push(2);
    original.push(3);
    MutantStack<int> copy(original);
    MutantStack<int> assigned;
    assigned = original;
    std::cout << "Original top: " << original.top() << std::endl;
    std::cout << "Copy top: " << copy.top() << std::endl;
    std::cout << "Assigned top: " << assigned.top() << std::endl;
}

void test_with_different_types()
{
    std::cout << "\n=== Template Flexibility (string) ===" << std::endl;
    MutantStack<std::string> sstack;
    sstack.push("hello");
    sstack.push("world");
    sstack.push("!");
    for (MutantStack<std::string>::iterator it = sstack.begin(); it != sstack.end(); ++it)
        std::cout << *it << " ";
    std::cout << std::endl;
}

void test_equivalent_list_output()
{
    std::cout << "\n=== Comparison with std::list ===" << std::endl;

    MutantStack<int> mstack;
    std::list<int> lstack;

    for (int i = 1; i <= 5; ++i)
    {
        mstack.push(i * 100);
        lstack.push_back(i * 100);
    }
    std::cout << "MutantStack: ";
    for (MutantStack<int>::iterator it = mstack.begin(); it != mstack.end(); ++it)
        std::cout << *it << " ";
    std::cout << "\nstd::list:     ";
    for (std::list<int>::iterator it = lstack.begin(); it != lstack.end(); ++it)
        std::cout << *it << " ";
    std::cout << std::endl;
}

int main()
{
    test_basic_operations();
    test_iteration();
    test_reverse_iteration();
    test_const_iteration();
    test_copy_constructor_and_assignment();
    test_with_different_types();
    test_equivalent_list_output();

    return 0;
}