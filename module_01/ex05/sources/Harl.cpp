/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nzharkev <nzharkev@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 10:42:39 by nzharkev          #+#    #+#             */
/*   Updated: 2025/03/24 10:35:50 by nzharkev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Harl.hpp"

void Harl::debug() {
	std::cout << "\t\033[1;90;47mThis is the DEBUG level\033[0m" << std::endl;
	std::cout << "You know, I’ve been looking at old maps, and something doesn’t add up...\n"
			  << "There’s no mention of Finland before the 20th century.\nCoincidence? I think not!\n"
			  << std::endl;
};
void Harl::info() {
	std::cout << "\t\033[1;97;44mThis is the INFO level\033[0m" << std::endl;
	std::cout << "Think about it: No one *actually* knows someone who has been to Finland.\n"
			  << "It’s always ‘a friend of a friend.’\nSuspicious, don’t you think?\n"
			  << std::endl;
};
void Harl::warning() {
	std::cout << "\t\033[1;37;43mThis is the WARNING level\033[0m" << std::endl;
	std::cout << "Wake up, people!\nThe so-called ‘Finnish people’ are just Swedes, Russians, and Estonians playing along with the hoax.\n"
			  << "Big Geography has been lying to us for decades!\n"
			  << std::endl;
};
void Harl::error() {
	std::cout << "\t\033[1;97;41mThis is the ERROR level\033[0m" << std::endl;
	std::cout << "This is unacceptable!\nI refuse to be gaslit into believing in a country that is clearly" << " just open sea used by Japan and Russia for secret fishing deals.\nWAKE UP!\n"
			  << std::endl;
};

void Harl::complain(std::string level)
{
	void (Harl::*complaints[])() = {
		&Harl::debug,
		&Harl::info,
		&Harl::warning,
		&Harl::error};
	std::string levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	for (int i = 0; i < 4; i++)
	{
		if (levels[i] == level)
		{
			(this->*complaints[i])();
			return;
		}
	}
	std::cout << "\t\033[1;95mThis is the INVALID level\033[0m" << std::endl;
	std::cout << "Harl is too deep in the truth to even acknowledge such nonsense levels!\n"
			  << std::endl;
}
