/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nzharkev <nzharkev@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 12:55:32 by nzharkev          #+#    #+#             */
/*   Updated: 2025/03/12 15:28:14 by nzharkev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Phonebook.hpp"
#include <iomanip>

PhoneBook::PhoneBook()
{
	_Id = 0;
	std::cout << "---------------------------------------------" << std::endl;
	std::cout << "|                                           |" << std::endl;
	std::cout << "|                                           |" << std::endl;
	std::cout << "|                                           |" << std::endl;
	std::cout << "|        ***********                        |" << std::endl;
	std::cout << "|       *           *                       |" << std::endl;
	std::cout << "|       *            *                      |" << std::endl;
	std::cout << "|       *             *                     |" << std::endl;
	std::cout << "|       *            *                      |" << std::endl;
	std::cout << "|       *           *                       |" << std::endl;
	std::cout << "|       *   ********                        |" << std::endl;
	std::cout << "|       *   *                               |" << std::endl;
	std::cout << "|       *   *     hone                      |" << std::endl;
	std::cout << "|       *   *                               |" << std::endl;
	std::cout << "|       *****         **********            |" << std::endl;
	std::cout << "|                    *           *          |" << std::endl;
	std::cout << "|                    *            *         |" << std::endl;
	std::cout << "|                    *           *          |" << std::endl;
	std::cout << "|                    *          *           |" << std::endl;
	std::cout << "|                    *           *          |" << std::endl;
	std::cout << "|                    *            *         |" << std::endl;
	std::cout << "|                    *             *        |" << std::endl;
	std::cout << "|                    *            *         |" << std::endl;
	std::cout << "|                    *           *  ook     |" << std::endl;
	std::cout << "|                     ***********           |" << std::endl;
	std::cout << "---------------------------------------------" << std::endl;
}

PhoneBook::~PhoneBook()
{
	std::cout << "All your contacts are lost forever" << std::endl;
}

void PhoneBook::add()
{
	std::string str;
	if (_Id == 8)
		_Id = 0;
	std::cout << "---------------------------------------------" << std::endl;
	auto getInput = [](const  std::string &prompt) -> std::string {
		std::string input;
		while (input.empty())
		{
			std::cout << prompt;
			if (!std::getline(std::cin, input))
				return "";
		}
		return (input);
	};
	_Contacts[_Id].setFirstName(getInput("First name: "));
	_Contacts[_Id].setLastName(getInput("Last name: "));
	_Contacts[_Id].setNickName(getInput("Nick name: "));
	_Contacts[_Id].setNumber(getInput("Phone number: "));
	_Contacts[_Id].setSecret(getInput("Darkest secret: "));
	std::cout << "---------------------------------------------" << std::endl;
	_Id++;
}

void PhoneBook::contactInfo(Contact contact)
{
	std::cout << "---------------------------------------------" << std::endl;
	std::cout << "---------------------------------------------" << std::endl;
	std::cout << "  First name:   " << contact.getFirstName() << std::endl;
	std::cout << "  Last name:    " << contact.getLastName() << std::endl;
	std::cout << "  Nick name:    " << contact.getNickName() << std::endl;
	std::cout << "  Phone number: " << contact.getNumber() << std::endl;
	std::cout << "  Dark secret: " << contact.getSecret() << std::endl;
	std::cout << "---------------------------------------------" << std::endl;
}

void PhoneBook::search()
{
	std::string input;
	int index;
	if (!contactsPage(_Contacts))
	{
		std::cout << "Oh no! Looks like your phonebook is empty!" << std::endl;
		return ;
	}
	while(true)
	{
		std::cout << "Insert index: ";
		if (!std::getline(std::cin, input) || input.empty())
		{
			std::cout << "Invalid index!" << std::endl;
			continue;
		}
		if (input.length() == 1 && input[0] >= '1' && input[0] <= '8')
		{
			index = input[0] - '1';
			if (!_Contacts[index].getFirstName().empty())
			{
				contactInfo(_Contacts[index]);
				break ;
			}
		}
		std::cout << "Invalid index!" << std::endl;
	}
}

std::string columnWidth(std::string column, size_t width)
{
	if (column.size() > width)
	{
		column.resize(width);
		column[column.size() - 1] = '.';
	}
	return (column);
}

std::string fillWithSpace(int amount)
{
	std::string spaces;
	while (amount--)
		spaces.append(" ");
	return (spaces);
}

int contactsPage(Contact contacts[8])
{
	int i = 0;
	char c = '0';
	std::string input;

	std::cout << std::setw(44) << std::setfill('-') << "-" << "|" << std::endl;
	std::cout << std::setfill(' ') << "|" << std::setw(10) << "Index" << "|"
			<< std::setw(10) << "First Name" << "|"
			<< std::setw(10) << "Last Name" << "|"
			<< std::setw(10) << "Nick Name" << "|" << std::endl;
	std::cout << std::setw(44) << std::setfill('-') << "-" << std::endl;
	// std::cout << "|     Index|First Name| Last Name|  Nickname|" << std::endl;
	// std::cout << "|----------|----------|----------|----------|" << std::endl;
	while (++c <= '8')
	{
		if (contacts[c - 1 - '0'].getFirstName().size() && ++i)
		{
			input = c;
			input = columnWidth(input, 10);
			std::cout << "|" << fillWithSpace(10 - input.size()) << input;
			input = columnWidth(contacts[c - 1 - '0'].getFirstName(), 10);
			std::cout << "|" << fillWithSpace(10 - input.size()) << input ;
			input = columnWidth(contacts[c - 1 - '0'].getLastName(), 10);
			std::cout << "|" << fillWithSpace(10 - input.size()) << input ;
			input = columnWidth(contacts[c - 1 - '0'].getNickName(), 10);
			std::cout << "|" << fillWithSpace(10 - input.size()) << input ;
			std::cout << "|" << std::endl;
		}
	}
	std::cout << std::setw(44) << std::setfill('-') << "-" << std::endl;
	return (i);
}
