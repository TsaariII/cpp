/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nzharkev <nzharkev@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 10:45:01 by nzharkev          #+#    #+#             */
/*   Updated: 2025/03/21 09:37:05 by nzharkev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Fixed.hpp"

Fixed::Fixed() : _FixedNum(0) {std::cout << "Default constructor called" << std::endl; }

Fixed::Fixed(const Fixed &copy) : _FixedNum(copy._FixedNum) {
	std::cout << "Copy constructor called" << std::endl;
	Fixed::operator=(copy);
}

Fixed::Fixed(const int num) {
	std::cout << "Int constructor called" << std::endl;
	_FixedNum = num << _FractBits;
}

Fixed::Fixed(const float fNum) {
	std::cout << "Float constructor called" << std::endl;
	_FixedNum = roundf(fNum * (1 << _FractBits));
}

Fixed &Fixed::operator=(const Fixed &copy) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &copy)
	{
		_FixedNum = copy.getRawBits();
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
