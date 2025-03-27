/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nzharkev <nzharkev@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 10:44:11 by nzharkev          #+#    #+#             */
/*   Updated: 2025/03/27 15:22:07 by nzharkev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Fixed.hpp"

// int main( void )
// {
// 	Fixed a;
// 	Fixed b(a);
// 	Fixed c;
// 	c = b;
// 	std::cout << a.getRawBits() << std::endl;
// 	std::cout << b.getRawBits() << std::endl;
// 	std::cout << c.getRawBits() << std::endl;
// 	return 0;
// }


#include <iostream>
#include <climits>
#include "../includes/Fixed.hpp"

void test_default_constructor() {
	std::cout << "\n--- Test: Default Constructor ---" << std::endl;
	Fixed a;
	std::cout << "Raw bits: " << a.getRawBits() << std::endl;
}

void test_copy_constructor() {
	std::cout << "\n--- Test: Copy Constructor ---" << std::endl;
	Fixed a;
	a.setRawBits(42);
	Fixed b(a);
	std::cout << "Original raw: " << a.getRawBits() << std::endl;
	std::cout << "Copied raw:   " << b.getRawBits() << std::endl;
}

void test_copy_assignment() {
	std::cout << "\n--- Test: Copy Assignment ---" << std::endl;
	Fixed a;
	a.setRawBits(99);
	Fixed b;
	b = a;
	std::cout << "Source raw:      " << a.getRawBits() << std::endl;
	std::cout << "Assigned raw:    " << b.getRawBits() << std::endl;
}

void test_self_assignment() {
	std::cout << "\n--- Test: Self Assignment ---" << std::endl;
	Fixed a;
	a.setRawBits(123);
	//a = a;
	Fixed* ptr = &a;
	a = *ptr; // Self-assignment
	std::cout << "After self-assign: " << a.getRawBits() << std::endl;
}

void test_set_and_get_raw_bits() {
	std::cout << "\n--- Test: Set/Get Raw Bits ---" << std::endl;
	Fixed a;
	a.setRawBits(-999);
	std::cout << "Raw bits after set: " << a.getRawBits() << std::endl;
	a.setRawBits(INT_MAX);
	std::cout << "Raw bits after INT_MAX: " << a.getRawBits() << std::endl;
	a.setRawBits(INT_MIN);
	std::cout << "Raw bits after INT_MIN: " << a.getRawBits() << std::endl;
}

int main() {
	test_default_constructor();
	test_copy_constructor();
	test_copy_assignment();
	test_self_assignment();
	test_set_and_get_raw_bits();

	std::cout << "\n--- End of tests. Watch for destructor order ---" << std::endl;
	return 0;
}
