/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nzharkev <nzharkev@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 10:06:58 by nzharkev          #+#    #+#             */
/*   Updated: 2025/03/13 12:21:19 by nzharkev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
# include "Contact.hpp"
# include <string>
# include <iostream>

class PhoneBook
{
	private:
		Contact _Contacts[8];
		int _Id;
	public:
		PhoneBook();
		~PhoneBook();
		void add();
		void search();
		void contactInfo(Contact contact);
};

void firstPage();
bool contactsPage(Contact contacts[8]);