/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nzharkev <nzharkev@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 10:44:11 by nzharkev          #+#    #+#             */
/*   Updated: 2025/03/27 15:02:05 by nzharkev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Fixed.hpp"
#include "../includes/Point.hpp"
#include <iomanip>

void printGrid(Point const &a, Point const &b, Point const &c, Point const &point)
{
	int height = 10;
	int width = 10;
	std::cout << "Point a has coordinates\nX: " << a.getX() << "\nY: " << a.getY() << std::endl;
	std::cout << "Point b has coordinates\nX: " << b.getX() << "\nY: " << b.getY() << std::endl;
	std::cout << "Point c has coordinates\nX: " << c.getX() << "\nY: " << c.getY() << std::endl;
	std::cout << "Point point has coordinates\nX: " << point.getX() << "\nY: " << point.getY() << std::endl;
	std::cout << "\n\tGrid\n" << std::endl;
	for (int y = height; y >= 0; y--)
	{
		for (int x = 0; x <= width; x++)
		{
			if (a.getX().toInt() == x && a.getY().toInt() == y)
				std::cout << std::setw(2) << "\033[36m a\033[0m";
			else if (b.getX().toInt() == x && b.getY().toInt() == y)
				std::cout << std::setw(2) << "\033[36m b\033[0m";
			else if (c.getX().toInt() == x && c.getY().toInt() == y)
				std::cout << std::setw(2) << "\033[36m c\033[0m";
			else if (point.getX().toInt() == x && point.getY().toInt() == y)
				std::cout << std::setw(2) << "\033[33m p\033[0m";
			else
				std::cout << std::setw(2) << "*";
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
	if (bsp(a, b, c, point))
		std::cout << "\033[1;30;42mInside triangle\033[0m\n" << std::endl;
	else
		std::cout << "\033[1;97;41mOutside or on the edge of triangle\033[0m\n" << std::endl;
}

int main()
{
	Point a(3 , 1);
	Point b(7 , 4);
	Point c(3 , 6);

	Point in(4, 4);
	Point out(0, 0);
	Point edge(3,3);
	printGrid(a, b, c, in);
	printGrid(a, b, c, out);
	printGrid(a, b, c, edge);
}
