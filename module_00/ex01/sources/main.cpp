/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nzharkev <nzharkev@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 10:02:12 by nzharkev          #+#    #+#             */
/*   Updated: 2025/03/10 11:07:28 by nzharkev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Phonebook.hpp"

void firstPage()
{
	std::cout << "---------------------------------------------" << std::endl;
	std::cout << "|                                           |" << std::endl;
	std::cout << "|                                           |" << std::endl;
	std::cout << "|                                           |" << std::endl;
	std::cout << "|                                           |" << std::endl;
	std::cout << "|                                           |" << std::endl;
	std::cout << "|                                           |" << std::endl;
	std::cout << "|                 PHONEBOOK                 |" << std::endl;
	std::cout << "|                                           |" << std::endl;
	std::cout << "|                                           |" << std::endl;
	std::cout << "|                                           |" << std::endl;
	std::cout << "|                                           |" << std::endl;
	std::cout << "|     Commands:                             |" << std::endl;
	std::cout << "|                                           |" << std::endl;
	std::cout << "|     ADD: save new contact                 |" << std::endl;
	std::cout << "|                                           |" << std::endl;
	std::cout << "|                                           |" << std::endl;
	std::cout << "|     SEARCH: display specific contact      |" << std::endl;
	std::cout << "|                                           |" << std::endl;
	std::cout << "|                                           |" << std::endl;
	std::cout << "|     EXIT: Program quits                   |" << std::endl;
	std::cout << "|                                           |" << std::endl;
	std::cout << "|                                           |" << std::endl;
	std::cout << "|                                           |" << std::endl;
	std::cout << "|                                           |" << std::endl;
	std::cout << "---------------------------------------------" << std::endl;
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
