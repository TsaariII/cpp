/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nzharkev <nzharkev@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 10:45:01 by nzharkev          #+#    #+#             */
/*   Updated: 2025/03/26 11:32:52 by nzharkev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Fixed.hpp"

Fixed::Fixed() : _FixedNum(0) {}

Fixed::Fixed(const Fixed &copy) : _FixedNum(copy._FixedNum) {}

Fixed::Fixed(const int num) { _FixedNum = num << _FractBits; }

Fixed::Fixed(const float fNum) { _FixedNum = roundf(fNum * (1 << _FractBits)); }

Fixed &Fixed::operator=(const Fixed &copy) {
	if (this != &copy)
		_FixedNum = copy.getRawBits();
	return (*this);
}

Fixed::~Fixed() {}

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

bool Fixed::operator>(const Fixed &copy) const { return _FixedNum > copy._FixedNum; }
bool Fixed::operator<(const Fixed &copy) const { return _FixedNum < copy._FixedNum; }
bool Fixed::operator>=(const Fixed &copy) const { return _FixedNum >= copy._FixedNum; }
bool Fixed::operator<=(const Fixed &copy) const { return _FixedNum <= copy._FixedNum; }
bool Fixed::operator==(const Fixed &copy) const { return _FixedNum == copy._FixedNum; }
bool Fixed::operator!=(const Fixed &copy) const { return _FixedNum != copy._FixedNum; }

Fixed Fixed::operator+(const Fixed &copy) const { return Fixed(this->toFloat() + copy.toFloat()); }
Fixed Fixed::operator-(const Fixed &copy) const { return Fixed(this->toFloat() - copy.toFloat()); }
Fixed Fixed::operator*(const Fixed &copy) const
{
	Fixed result;
	result.setRawBits((this->_FixedNum * copy._FixedNum) >> _FractBits);
	return result;
}

Fixed Fixed::operator/(const Fixed &copy) const
{
	if (copy._FixedNum == 0)
		return Fixed();
	Fixed result;
	result.setRawBits(this->toFloat() / copy.toFloat());
	return result;
}

Fixed& Fixed::operator++() {
	_FixedNum += 1;
	return *this;
};
Fixed Fixed::operator++(int) {
	Fixed temp = *this;
	_FixedNum += 1;
	return temp;
};
Fixed& Fixed::operator--() {
	_FixedNum -= 1;
	return *this;
};
Fixed Fixed::operator--(int) {
	Fixed temp = *this;
	_FixedNum -= 1;
	return temp;
};

Fixed& Fixed::min(Fixed &a, Fixed &b) { return a < b ? a : b; }
const Fixed& Fixed::min(const Fixed &a, const Fixed &b) { return a < b ? a : b; }
Fixed& Fixed::max(Fixed &a, Fixed &b) { return a > b ? a : b; }
const Fixed& Fixed::max(const Fixed &a, const Fixed &b) { return a > b ? a : b; }

