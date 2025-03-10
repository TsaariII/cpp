/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nzharkev <nzharkev@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 12:55:32 by nzharkev          #+#    #+#             */
/*   Updated: 2025/03/10 12:17:16 by nzharkev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Phonebook.hpp"

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
	if (_Id == 7)
		_Id = 0;
	std::cout << "---------------------------------------------" << std::endl;
	std::cout << "First name: " << std::endl;
	if (std::getline(std::cin, str) && str != "")
		_Contacts[_Id].setFirstName(str);
	str = "";
	std::cout << "Last name: " << std::endl;
	if (std::getline(std::cin, str) && str != "")
		_Contacts[_Id].setLastName(str);
	str = "";
	std::cout << "Nick name: " << std::endl;
	if (std::getline(std::cin, str) && str != "")
		_Contacts[_Id].setNickName(str);
	str = "";
	std::cout << "Phone number: " << std::endl;
	if (std::getline(std::cin, str) && str != "")
		_Contacts[_Id].setNumber(str);
	str = "";
	std::cout << "Darkest secret: " << std::endl;
	if (std::getline(std::cin, str) && str != "")
		_Contacts[_Id].setSecret(str);
	str = "";
	std::cout << "---------------------------------------------" << std::endl;
	std::cout << "---------------------------------------------" << std::endl;
	std::cout << "  First name:   " << _Contacts[_Id].getFirstName() << std::endl;
	std::cout << "  Last name:    " << _Contacts[_Id].getLastName() << std::endl;
	std::cout << "  Nick name:    " << _Contacts[_Id].getNickName() << std::endl;
	std::cout << "  Phone number: " << _Contacts[_Id].getNumber() << std::endl;
	std::cout << "  Dark secret: " << _Contacts[_Id].getSecret() << std::endl;
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
	if (!contactsPage(_Contacts))
	{
		std::cout << "Oh no! Looks like your phonebook is empty!" << std::endl;
		return ;
	}
	while(!std::cin.eof())
	{
		std::cout << "Insert index: ";
		if (std::getline(std::cin, input) && input != "")
		{
			if (input.size() == 1 && input[0] >= '1' && input[0] <= '8'\
				&& _Contacts[input[0] - 1 - '0'].getFirstName().size())
				break ;
		}
		if (input != "")
			std::cout << "Invalid index!" << std::endl;
	}
	if (!std::cin.eof())
		contactInfo(_Contacts[input[0] - 1 - '0']);
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

	std::cout << "---------------------------------------------" << std::endl;
	std::cout << "|Index     |First Name|Last Name |Nickname  |" << std::endl;
	std::cout << "|----------|----------|----------|----------|" << std::endl;
	while (++c <= '8')
	{
		if (contacts[c - 1 - '0'].getFirstName().size() && ++i)
		{
			input = c;
			input = columnWidth(input, 10);
			std::cout << "|" << fillWithSpace(6 - input.size()) << input << fillWithSpace(5 - input.size());
			input = columnWidth(contacts[c - 1 - '0'].getFirstName(), 10);
			std::cout << "|" << input << fillWithSpace(10 - input.size());
			input = columnWidth(contacts[c - 1 - '0'].getLastName(), 10);
			std::cout << "|" << input << fillWithSpace(10 - input.size());
			input = columnWidth(contacts[c - 1 - '0'].getNickName(), 10);
			std::cout << "|" << input << fillWithSpace(10 - input.size());
			std::cout << "|" << std::endl;
		}
	}
	std::cout << "---------------------------------------------" << std::endl;
	return (i);
}
