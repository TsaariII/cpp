/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nzharkev <nzharkev@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 13:16:36 by nzharkev          #+#    #+#             */
/*   Updated: 2025/03/26 11:31:08 by nzharkev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "Fixed.hpp"

class Point
{
	private:
		const Fixed _X;
		const Fixed _Y;
	public:
		Point();
		Point(const float x, const float y);
		Point(const Point &copy);
		Point &operator=(const Point &copy);
		~Point();
		Fixed getX() const;
		Fixed getY() const;
};

bool bsp( Point const a, Point const b, Point const c, Point const point);

// Area = 1/2 * |x1(y2 - y3) + x2(y3 - y1) + x3(y1 - y2)|
Fixed area(Point const& p1, Point const& p2, Point const &p3);
