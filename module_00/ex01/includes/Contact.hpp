/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nzharkev <nzharkev@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 10:16:39 by nzharkev          #+#    #+#             */
/*   Updated: 2025/03/05 14:14:27 by nzharkev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <string>
# include <iostream>

class Contact
{
	private:
		std::string	_FirstName;
		std::string	_LastName;
		std::string	_NickName;
		std::string	_Number;
		std::string	_Secret;
	public:
		Contact();
		~Contact();
		std::string getFirstName();
		std::string getLastName();
		std::string getNickName();
		std::string getNumber();
		void setFirstName(std::string info);
		void setLastName(std::string info);
		void setNickName(std::string info);
		void setNumber(std::string info);
		void setSecret(std::string info);
};
