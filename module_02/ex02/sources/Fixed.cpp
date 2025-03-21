/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nzharkev <nzharkev@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 10:45:01 by nzharkev          #+#    #+#             */
/*   Updated: 2025/03/22 14:13:21 by nzharkev         ###   ########.fr       */
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

bool Fixed::operator>(const Fixed &copy) { return _FixedNum > copy._FixedNum; }
bool Fixed::operator<(const Fixed &copy) { return _FixedNum < copy._FixedNum; }
bool Fixed::operator>=(const Fixed &copy) { return _FixedNum >= copy._FixedNum; }
bool Fixed::operator<=(const Fixed &copy) { return _FixedNum <= copy._FixedNum; }
bool Fixed::operator==(const Fixed &copy) { return _FixedNum == copy._FixedNum; }
bool Fixed::operator!=(const Fixed &copy) { return _FixedNum != copy._FixedNum; }

Fixed Fixed::operator+(const Fixed &copy) const { return Fixed(this->toFloat() + copy.toFloat()); };
Fixed Fixed::operator-(const Fixed &copy) const { return Fixed(this->toFloat() - copy.toFloat()); };
Fixed Fixed::operator*(const Fixed &copy) const { return Fixed(this->toFloat() * copy.toFloat()); };
Fixed Fixed::operator/(const Fixed &copy) const {
	if (copy._FixedNum == 0)
		return Fixed(this->_FixedNum);
	return Fixed(this->toFloat() / copy.toFloat()); };

Fixed Fixed::operator++() {
	_FixedNum += 1;
	return *this;
};
Fixed Fixed::operator++(int) {
	Fixed temp = *this;
	_FixedNum += 1;
	return temp;
};
Fixed Fixed::operator--() {
	_FixedNum -= 1;
	return *this;
};
Fixed Fixed::operator--(int) {
	Fixed temp = *this;
	_FixedNum -= 1;
	return temp;
};
