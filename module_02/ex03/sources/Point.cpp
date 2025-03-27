/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nzharkev <nzharkev@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 13:19:54 by nzharkev          #+#    #+#             */
/*   Updated: 2025/03/26 11:31:30 by nzharkev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Point.hpp"

Point::Point() : _X(0), _Y(0) {}

Point::Point(const float x, const float y) : _X(x), _Y(y) {}

Point::Point(const Point &copy) : _X(copy._X), _Y(copy._Y) {}

Point &Point::operator=(const Point &copy) {
	(void)copy;
	return (*this);
}

Point::~Point() {}

Fixed Point::getX() const {return _X; }
Fixed Point::getY() const {return _Y; }

Fixed area(Point const &p1, Point const &p2, Point const &p3)
{
	float result = (p1.getX().toFloat() * (p2.getY().toFloat() - p3.getY().toFloat())
					 + p2.getX().toFloat() * (p3.getY().toFloat() - p1.getY().toFloat())
					 + p3.getX().toFloat() * (p1.getY().toFloat() - p2.getY().toFloat())) / 2.0f;
	return Fixed(result < 0 ? -result : result);
}

bool bsp( Point const a, Point const b, Point const c, Point const point)
{
	Fixed triangle = area(a, b, c);
	Fixed a1 = area(point, b, c);
	Fixed a2 = area(a, point, c);
	Fixed a3 = area(a, b, point);

	if (a1 == Fixed(0) | a2 == Fixed(0) | a3 == Fixed(0))
		return false;
	return triangle == a1 + a2 + a3;
}
