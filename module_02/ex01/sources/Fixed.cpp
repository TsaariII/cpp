/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nzharkev <nzharkev@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 10:45:01 by nzharkev          #+#    #+#             */
/*   Updated: 2025/03/28 16:35:38 by nzharkev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Fixed.hpp"

Fixed::Fixed() : _FixedNum(0) {std::cout << "Default constructor called" << std::endl; }

Fixed::Fixed(const Fixed &copy) {
	std::cout << "Copy constructor called" << std::endl;
	this->operator=(copy);
}

Fixed::Fixed(const int num) {
	std::cout << "Int constructor called" << std::endl;
	try {
		if (num > (INT_MAX >> _FractBits) || num < (INT_MIN >> _FractBits))
			throw std::overflow_error("Overflow detected");
		_FixedNum = num << _FractBits;
	}
	catch (const std::exception &e) {
		std::cerr << e.what() << std::endl;
		_FixedNum = 0;
	}
}

Fixed::Fixed(const float fNum) {
	std::cout << "Float constructor called" << std::endl;
	try {
		float scaled = fNum * (1 << _FractBits);
		if (scaled > static_cast<float>(INT_MAX) || scaled < static_cast<float>(INT_MIN))
			throw std::overflow_error("Overflow detected");
		_FixedNum = roundf(fNum * (1 << _FractBits));
	}
	catch (const std::exception &e) {
		std::cerr << e.what() << std::endl;
		_FixedNum = 0;
	}
}

Fixed &Fixed::operator=(const Fixed &copy) {
	if (this != &copy)
	{
		_FixedNum = copy._FixedNum;
		std::cout << "Copy assignment operator called" << std::endl;
	}
	return (*this);
}

Fixed::~Fixed() { std::cout << "Destructor called" << std::endl; }

void Fixed::setRawBits(int const raw) { _FixedNum = raw; }

int Fixed::getRawBits(void) const {
	std::cout << "getRawBits member function called" << std::endl;
	return _FixedNum;
}

float Fixed::toFloat( void ) const { return (float)_FixedNum / (1 << _FractBits); }

int Fixed::toInt( void ) const { return _FixedNum >> _FractBits; }

std::ostream &operator<<(std::ostream &out, const Fixed &fixed) {
	out << fixed.toFloat();
	return out;
}
