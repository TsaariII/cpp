/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nzharkev <nzharkev@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 10:45:01 by nzharkev          #+#    #+#             */
/*   Updated: 2025/03/31 10:27:04 by nzharkev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Fixed.hpp"

Fixed::Fixed() : _FixedNum(0) {}

Fixed::Fixed(const Fixed &copy) { this->operator=(copy); }

Fixed::Fixed(const int num) {
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
		_FixedNum = copy._FixedNum;
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

Fixed Fixed::operator+(const Fixed &copy) const
{
	try {
		float result = this->toFloat() + copy.toFloat();
		float scaled = result * (1 << _FractBits);
		if (scaled > static_cast<float>(INT_MAX) || scaled < static_cast<float>(INT_MIN))
			throw std::overflow_error("Overflow detected");
		return Fixed(result);
	}
	catch (const std::exception &e){
		std::cerr << e.what() << std::endl;
		return Fixed();
	}
};

Fixed Fixed::operator-(const Fixed &copy) const
{
	try {
		float result = this->toFloat() - copy.toFloat();
		float scaled = result * (1 << _FractBits);
		if (scaled > static_cast<float>(INT_MAX) || scaled < static_cast<float>(INT_MIN))
			throw std::overflow_error("Overflow detected");
		return Fixed(result);
	}
	catch (const std::exception &e){
		std::cerr << e.what() << std::endl;
		return Fixed();
	}
};
Fixed Fixed::operator*(const Fixed &copy) const
{
	try {
		float result = this->toFloat() * copy.toFloat();
		float scaled = result * (1 << _FractBits);
		if (scaled > static_cast<float>(INT_MAX) || scaled < static_cast<float>(INT_MIN))
			throw std::overflow_error("Overflow detected");
		return Fixed(result);
	}
	catch (const std::exception &e){
		std::cerr << e.what() << std::endl;
		return Fixed();
	}
};
Fixed Fixed::operator/(const Fixed &copy) const {
	try {
		if (copy._FixedNum == 0)
			return Fixed(this->_FixedNum);
		float result = this->toFloat() + copy.toFloat();
		float scaled = result * (1 << _FractBits);
		if (scaled > static_cast<float>(INT_MAX) || scaled < static_cast<float>(INT_MIN))
			throw std::overflow_error("Overflow detected");
		return Fixed(result);
	}
	catch (const std::exception &e){
		std::cerr << e.what() << std::endl;
		return Fixed();
	}
};

Fixed& Fixed::operator++() {
	if (_FixedNum == INT_MAX)
	{
		std::cerr << "Overflow detected" << std::endl;
		std::exit(EXIT_FAILURE);
	}
	_FixedNum += 1;
	return *this;
};

Fixed Fixed::operator++(int) {
	if (_FixedNum == INT_MAX)
	{
		std::cerr << "Overflow detected" << std::endl;
		std::exit(EXIT_FAILURE);
	}
	Fixed temp = *this;
	_FixedNum += 1;
	return temp;
};

Fixed& Fixed::operator--() {
	if (_FixedNum == INT_MIN)
	{
		std::cerr << "Overflow detected" << std::endl;
		std::exit(EXIT_FAILURE);
	}
	_FixedNum -= 1;
	return *this;
};

Fixed Fixed::operator--(int) {
	if (_FixedNum == INT_MIN)
	{
		std::cerr << "Overflow detected" << std::endl;
		std::exit(EXIT_FAILURE);
	}
	Fixed temp = *this;
	_FixedNum -= 1;
	return temp;
};

Fixed& Fixed::min(Fixed &a, Fixed &b) { return a < b ? a : b; }
const Fixed& Fixed::min(const Fixed &a, const Fixed &b) { return a < b ? a : b; }
Fixed& Fixed::max(Fixed &a, Fixed &b) { return a > b ? a : b; }
const Fixed& Fixed::max(const Fixed &a, const Fixed &b) { return a > b ? a : b; }

