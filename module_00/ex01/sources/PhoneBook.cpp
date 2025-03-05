/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nzharkev <nzharkev@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 12:55:32 by nzharkev          #+#    #+#             */
/*   Updated: 2025/03/05 15:17:51 by nzharkev         ###   ########.fr       */
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
	std::cin >> str;
	_Contacts[_Id].setFirstName(str);
	str = "";
	std::cout << "Last name: " << std::endl;
	std::cin >> str;
	_Contacts[_Id].setLastName(str);
	str = "";
	std::cout << "Nick name: " << std::endl;
	std::cin >> str;
	_Contacts[_Id].setNickName(str);
	str = "";
	std::cout << "Phone number: " << std::endl;
	std::cin >> str;
	_Contacts[_Id].setNumber(str);
	str = "";
	std::cout << "Darkest secret: " << std::endl;
	std::cin >> str;
	_Contacts[_Id].setSecret(str);
	str = "";
	std::cout << "---------------------------------------------" << std::endl;
	std::cout << "---------------------------------------------" << std::endl;
	std::cout << "  First name:   " << _Contacts[_Id].getFirstName() << std::endl;
	std::cout << "  Last name:    " << _Contacts[_Id].getLastName() << std::endl;
	std::cout << "  Nick name:    " << _Contacts[_Id].getNickName() << std::endl;
	std::cout << "  Phone number: " << _Contacts[_Id].getNumber() << std::endl;
	std::cout << "---------------------------------------------" << std::endl;
	firstPage();
	_Id++;
}

void PhoneBook::search()
{
	char c;
	std::string input;

	std::cout << "---------------------------------------------" << std::endl;
	std::cout << "|   Index  |First Name| Last Name| Nickname |" << std::endl;
	std::cout << "|----------|----------|----------|----------|" << std::endl;
	while (c <= '8')
	{
		
	}
	std::cout << "---------------------------------------------" << std::endl;
}

