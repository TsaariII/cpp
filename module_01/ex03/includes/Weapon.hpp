/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nzharkev <nzharkev@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 16:55:04 by nzharkev          #+#    #+#             */
/*   Updated: 2025/03/14 11:43:51 by nzharkev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <string>

class Weapon
{
private:
	std::string _Type;

public:
	Weapon(std::string weapon);
	Weapon();
	~Weapon();
	const std::string &getType() const;
	void setType(std::string tyep);
};
