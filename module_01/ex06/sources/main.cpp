/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nzharkev <nzharkev@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 11:10:53 by nzharkev          #+#    #+#             */
/*   Updated: 2025/03/24 10:42:55 by nzharkev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Harl.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << "To use this enter: ./harlFilter <level>" << std::endl;
		std::cout << "Levels:\nDEBUG, INFO, WARNING, ERROR" << std::endl;
		return 1;
	}

	Harl harl;
	harl.complain(argv[1]);
	return 0;
}
