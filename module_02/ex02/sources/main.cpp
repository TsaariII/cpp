/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nzharkev <nzharkev@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 10:44:11 by nzharkev          #+#    #+#             */
/*   Updated: 2025/03/28 16:24:45 by nzharkev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Fixed.hpp"

// int main( void ) {
// 	Fixed a;
// 	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
// 	std::cout << a << std::endl;
// 	std::cout << ++a << std::endl;
// 	std::cout << a << std::endl;
// 	std::cout << a++ << std::endl;
// 	std::cout << a << std::endl;
// 	std::cout << b << std::endl;
// 	std::cout << Fixed::max( a, b ) << std::endl;
// 	return 0;
// }



void test_arithmetic() {
	std::cout << "\n--- Arithmetic Tests ---\n";

	Fixed a(2.5f);
	Fixed b(1.25f);
	Fixed zero(0);

	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "a + b = " << a + b << std::endl;
	std::cout << "a - b = " << a - b << std::endl;
	std::cout << "a * b = " << a * b << std::endl;
	std::cout << "a / b = " << a / b << std::endl;
	std::cout << "a / zero = " << a / zero << " (should not crash or divide by 0)" << std::endl;
}

void test_comparisons() {
	std::cout << "\n--- Comparison Tests ---\n";

	Fixed a(5.5f);
	Fixed b(5.5f);
	Fixed c(2.25f);

	std::cout << std::boolalpha;
	std::cout << "a == b: " << (a == b) << std::endl;
	std::cout << "a != b: " << (a != b) << std::endl;
	std::cout << "a > c: " << (a > c) << std::endl;
	std::cout << "c < a: " << (c < a) << std::endl;
	std::cout << "a >= b: " << (a >= b) << std::endl;
	std::cout << "a <= b: " << (a <= b) << std::endl;
}

void test_increment_decrement() {
	std::cout << "\n--- Increment/Decrement Tests ---\n";

	Fixed a(1.5f);
	std::cout << "Original a: " << a << std::endl;

	std::cout << "++a: " << ++a << std::endl;
	std::cout << "a++: " << a++ << std::endl;
	std::cout << "After a++: " << a << std::endl;

	std::cout << "--a: " << --a << std::endl;
	std::cout << "a--: " << a-- << std::endl;
	std::cout << "After a--: " << a << std::endl;
}

void test_min_max() {
	std::cout << "\n--- Min/Max Tests ---\n";

	Fixed a(3.33f);
	Fixed b(4.44f);
	const Fixed c(1.11f);
	const Fixed d(2.22f);

	std::cout << "min(a, b): " << Fixed::min(a, b) << std::endl;
	std::cout << "max(a, b): " << Fixed::max(a, b) << std::endl;

	std::cout << "min(c, d): " << Fixed::min(c, d) << std::endl;
	std::cout << "max(c, d): " << Fixed::max(c, d) << std::endl;

	// Test reference behavior
	Fixed& refMin = Fixed::min(a, b);
	std::cout << "refMin before = " << refMin << std::endl;
	refMin.setRawBits(123456);
	std::cout << "a = " << a << ", b = " << b << std::endl;
}

int main() {
	test_arithmetic();
	test_comparisons();
	test_increment_decrement();
	test_min_max();

	std::cout << "\n✅ All tests completed.\n" << std::endl;
	return 0;
}
