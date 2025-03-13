/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nzharkev <nzharkev@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 10:02:12 by nzharkev          #+#    #+#             */
/*   Updated: 2025/03/13 12:30:55 by nzharkev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Phonebook.hpp"
#include <iomanip>

void firstPage()
{
    const int WIDTH = 45;
    std::cout << std::setw(WIDTH) << std::setfill('-') << "-" << std::endl;
    auto printEmptyLine = []() {
        std::cout << "| " << std::setw(WIDTH - 3) << std::setfill(' ') << " " << "|" << std::endl;
    };
    for (int i = 0; i < 7; i++) printEmptyLine();
    std::cout << "| " << std::setw(WIDTH - 3) << std::setfill(' ') << std::left << "PHONEBOOK" << "|" << std::endl;
    for (int i = 0; i < 4; i++) printEmptyLine();
    std::cout << "| " << std::setw(WIDTH - 3) << "Commands:" << "|" << std::endl;
    printEmptyLine();
    std::cout << "| " << std::setw(WIDTH - 3) << "ADD: Save new contact" << "|" << std::endl;
    printEmptyLine();
    std::cout << "| " << std::setw(WIDTH - 3) << "SEARCH: Display specific contact" << "|" << std::endl;
    printEmptyLine();
    std::cout << "| " << std::setw(WIDTH - 3) << "EXIT: Program quits" << "|" << std::endl;
    for (int i = 0; i < 5; i++) printEmptyLine();
    std::cout << std::setw(WIDTH) << std::setfill('-') << "-" << std::endl;
}

int main()
{
	PhoneBook pb;
	std::string cmd;

	while (cmd != "EXIT")
	{
		firstPage();
		std::getline(std::cin, cmd);
		if (cmd == "ADD")
			pb.add();
		else if (cmd == "SEARCH")
			pb.search();
		if (std::cin.eof())
		{
			std::cout << std::endl;
			return (0);
		}
	}
	return (0);
}
