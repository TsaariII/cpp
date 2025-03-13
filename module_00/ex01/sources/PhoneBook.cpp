/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nzharkev <nzharkev@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 12:55:32 by nzharkev          #+#    #+#             */
/*   Updated: 2025/03/13 12:21:45 by nzharkev         ###   ########.fr       */
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
	std::cout << "|" << std::setw(43) << std::setfill('-') << "-" << "|" << std::endl;
	auto getInput = [](const  std::string &prompt) -> std::string{
		std::string input;
		while (input.empty())
		{
			std::cout << prompt;
			
			if (!std::getline(std::cin, input))
			{
				std::cin.clear();
				std::cout << std::endl;
				return "";
			}
		}
		return (input);
	};
	_Contacts[_Id].setFirstName(getInput("| First name: "));
	_Contacts[_Id].setLastName(getInput("| Last name: "));
	_Contacts[_Id].setNickName(getInput("| Nick name: "));
	_Contacts[_Id].setNumber(getInput("| Phone number: "));
	_Contacts[_Id].setSecret(getInput("| Darkest secret: "));
	std::cout << "|" << std::setw(43) << std::setfill('-') << "-" << "|" << std::endl;
	_Id++;
}

void PhoneBook::contactInfo(Contact contact)
{
    std::cout << "|" << std::setw(43) << std::setfill('-') << "-" << "|" << std::endl;
    std::cout << "| " << std::left << std::setw(42) << std::setfill(' ') 
              << ("First name:   " + contact.getFirstName()) << "|" << std::endl;
    std::cout << "| " << std::left << std::setw(42) 
              << ("Last name:    " + contact.getLastName()) << "|" << std::endl;
    std::cout << "| " << std::left << std::setw(42) 
              << ("Nick name:    " + contact.getNickName()) << "|" << std::endl;
    std::cout << "| " << std::left << std::setw(42) 
              << ("Phone number: " + contact.getNumber()) << "|" << std::endl;
    std::cout << "| " << std::left << std::setw(42) 
              << ("Dark secret:  " + contact.getSecret()) << "|" << std::endl;
    std::cout << "|" << std::setw(43) << std::setfill('-') << "-" << "|" << std::endl;
}

void PhoneBook::search()
{
	std::string input;
	int index;
	if (!contactsPage(_Contacts))
	{
		std::cout << "| Oh no! Looks like your phonebook is empty!|" << std::endl;
		return ;
	}
	while(true && input != "EXIT")
	{
		std::cout << "Type EXIT or insert index: ";
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
		if (input != "EXIT")
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

bool contactsPage(Contact contacts[8])
{
	std::string input;
	std::cout << "|" << std::setw(43)   << std::setfill('-')  << "-" << "|" << std::endl;
	std::cout << std::setfill(' ') << "|" << std::setw(10) << "Index" << "|"
			<< std::setw(10) << "First Name" << "|"
			<< std::setw(10) << "Last Name" << "|"
			<< std::setw(10) << "Nick Name" << "|" << std::endl;
	std::cout << "|" << std::setw(43) << std::setfill('-') << "-" << "|" << std::endl;
	if (contacts[0].getFirstName().empty())
		return false;
    for (int i = 0; i < 8; ++i)
	{
        if (!contacts[i].getFirstName().empty())
		{
            std::cout << "| " << std::setw(9) << std::right << std::setfill(' ')  << (i + 1)
                      << "| " << std::setw(9) << std::right << std::setfill(' ')  << columnWidth(contacts[i].getFirstName(), 9)
                      << "| " << std::setw(9) << std::right << std::setfill(' ')  << columnWidth(contacts[i].getLastName(), 9) 
                      << "| " << std::setw(9) << std::right << std::setfill(' ')  << columnWidth(contacts[i].getNickName(), 9)
                      << "|" << std::endl;
        }
    }
	std::cout << "|" << std::setw(43) << std::setfill('-') << "-" << "|" << std::endl;
	return true;
}
