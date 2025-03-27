/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nzharkev <nzharkev@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 10:44:11 by nzharkev          #+#    #+#             */
/*   Updated: 2025/03/27 15:25:23 by nzharkev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Fixed.hpp"
#include <climits>
#include <cfloat>

// int main( void )
// {
// 	Fixed a;
// 	Fixed const b( 10 );
// 	Fixed const c( 42.42f );
// 	Fixed const d( b );
// 	a = Fixed( 1234.4321f );
// 	std::cout << "a is " << a << std::endl;
// 	std::cout << "b is " << b << std::endl;
// 	std::cout << "c is " << c << std::endl;
// 	std::cout << "d is " << d << std::endl;
// 	std::cout << "a is " << a.toInt() << " as integer" << std::endl;
// 	std::cout << "b is " << b.toInt() << " as integer" << std::endl;
// 	std::cout << "c is " << c.toInt() << " as integer" << std::endl;
// 	std::cout << "d is " << d.toInt() << " as integer" << std::endl;
// return 0;
// }


void test_int_constructor() {
	std::cout << "\n--- Test: Fixed(int) Constructor ---" << std::endl;
	Fixed a(0);
	Fixed b(1);
	Fixed c(-1);
	Fixed d(INT_MAX >> 8); // Max value that won't overflow when shifted
	Fixed e(INT_MIN >> 8); // Min value that won't overflow

	std::cout << "a = " << a << " (expected: 0)" << std::endl;
	std::cout << "b = " << b << " (expected: 1)" << std::endl;
	std::cout << "c = " << c << " (expected: -1)" << std::endl;
	std::cout << "d = " << d << " (expected: INT_MAX >> 8)" << std::endl;
	std::cout << "e = " << e << " (expected: INT_MIN >> 8)" << std::endl;
}

void test_float_constructor() {
	std::cout << "\n--- Test: Fixed(float) Constructor ---" << std::endl;
	Fixed a(0.0f);
	Fixed b(1.5f);
	Fixed c(-2.75f);
	Fixed d(123456.789f);
	Fixed e(1.0f / 256); // smallest representable increment

	std::cout << "a = " << a << std::endl;
	std::cout << "b = " << b << std::endl;
	std::cout << "c = " << c << std::endl;
	std::cout << "d = " << d << std::endl;
	std::cout << "e = " << e << " (should be ~0.0039...)" << std::endl;
}

void test_toInt_toFloat() {
	std::cout << "\n--- Test: toInt() and toFloat() ---" << std::endl;
	Fixed a(42.42f);
	Fixed b(-42.99f);
	Fixed c(0.0039f);

	std::cout << "a: toFloat = " << a.toFloat() << ", toInt = " << a.toInt() << std::endl;
	std::cout << "b: toFloat = " << b.toFloat() << ", toInt = " << b.toInt() << std::endl;
	std::cout << "c: toFloat = " << c.toFloat() << ", toInt = " << c.toInt() << std::endl;
}

void test_output_operator() {
	std::cout << "\n--- Test: operator<< Overload ---" << std::endl;
	Fixed a(5.25f);
	std::cout << "Expected float-like print: ";
	std::cout << a << std::endl;
}

int main() {
	test_int_constructor();
	test_float_constructor();
	test_toInt_toFloat();
	test_output_operator();

	std::cout << "\n--- End of tests ---" << std::endl;
	return 0;
}
