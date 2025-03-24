/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nzharkev <nzharkev@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 13:16:36 by nzharkev          #+#    #+#             */
/*   Updated: 2025/03/24 16:20:56 by nzharkev         ###   ########.fr       */
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
		Point &operator=(const Point &copy);
		Fixed getX();
		Fixed getY();
};
