/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nzharkev <nzharkev@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 10:44:11 by nzharkev          #+#    #+#             */
/*   Updated: 2025/03/27 12:39:57 by nzharkev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Fixed.hpp"
#include "../includes/Point.hpp"
#include <iomanip>

void printGrid(Point const &a, Point const &b, Point const &c, Point const &point)
{
	int height = 8;
	int width = 8;
	std::cout << "\n\tGrid\n" << std::endl;
	for (int y = height; y >= 0; y--)
	{
		for (int x = 0; x <= width; x++)
		{
			if (a.getX().toInt() == x && a.getY().toInt() == y)
				std::cout << std::setw(2) << "a";
			else if (b.getX().toInt() == x && b.getY().toInt() == y)
				std::cout << std::setw(2) << "b";
			else if (c.getX().toInt() == x && c.getY().toInt() == y)
				std::cout << std::setw(2) << "c";
			else if (point.getX().toInt() == x && point.getY().toInt() == y)
				std::cout << std::setw(2) << "p";
			else
				std::cout << std::setw(2) << "*";
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
}

int main()
{
	Point a(0 , 0);
	Point b(5 , 0);
	Point c(0 , 5);

	Point in(2, 2);
	Point out(5, 5);
	Point edge(0, 0);
	std::cout << "Point a has coordinats\nX: " << a.getX() << "\nY: " << a.getY() << std::endl;
	std::cout << "Point b has coordinats\nX: " << b.getX() << "\nY: " << b.getY() << std::endl;
	std::cout << "Point c has coordinats\nX: " << c.getX() << "\nY: " << c.getY() << std::endl;
	std::cout << "Point point has coordinats\nX: " << in.getX() << "\nY: " << in.getY() << std::endl;

	printGrid(a, b, c, in);
	if (bsp(a, b, c, in))
		std::cout << "Inside triangle" << std::endl;
	else
		std::cout << "Outside or onthe edge of triangle" << std::endl;
	// std::cout << bsp(a, b, c, out) << std::endl;
	// std::cout << bsp(a, b, c, edge) << std::endl;
}
