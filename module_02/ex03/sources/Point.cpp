/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nzharkev <nzharkev@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 13:19:54 by nzharkev          #+#    #+#             */
/*   Updated: 2025/03/24 15:29:52 by nzharkev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Point.hpp"

Point::Point() : _X(0), _Y(0) {}

Point::Point(const float x, const float y) : _X(x), _Y(y) {}

Point::Point(const Point &copy) : _X(copy._X), _Y(copy._Y) {
	std::cout << "Copy constructor called" << std::endl;
}

Point &Point::operator=(const Point &copy) {
	(void)copy;
	return (*this);
}

Point::~Point() {}

const float Point::get() {return _X; }
const float Point::get() {return ; }
