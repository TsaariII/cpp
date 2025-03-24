/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nzharkev <nzharkev@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 10:45:01 by nzharkev          #+#    #+#             */
/*   Updated: 2025/03/24 13:35:25 by nzharkev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Fixed.hpp"

Fixed::Fixed() : _FixedNum(0) {std::cout << "Default constructor called" << std::endl; }

Fixed::Fixed(const Fixed &copy) : _FixedNum(copy._FixedNum) {
	std::cout << "Copy constructor called" << std::endl;
}

Fixed &Fixed::operator=(const Fixed &copy) {
	if (this != &copy)
	{
		_FixedNum = copy.getRawBits();
		std::cout << "Copy assignment operator called" << std::endl;
	}
	return (*this);
}

Fixed::~Fixed() { std::cout << "Destructor called" << std::endl; }

void Fixed::setRawBits(int const raw) { _FixedNum = raw; }

int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return _FixedNum;
}

