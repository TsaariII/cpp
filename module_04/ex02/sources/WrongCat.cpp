/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nzharkev <nzharkev@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 14:51:21 by nzharkev          #+#    #+#             */
/*   Updated: 2025/04/03 15:20:23 by nzharkev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/WrongCat.hpp"

WrongCat::WrongCat() { std::cout << "Default wrong cat was created" << std::endl; _Type = "WrongCat"; }
WrongCat::WrongCat(std::string type)  { std::cout << "Created " << getType()  << std::endl; _Type = type; }
WrongCat::WrongCat(const WrongCat &copy) {  std::cout << "Created copy of " << getType()  << std::endl; _Type = copy._Type; }
WrongCat& WrongCat::operator=(const WrongCat &copy)
{
    std::cout << "Assigned " << getType()  << std::endl;
    if (this != &copy)
        _Type = copy._Type;
    return *this;
}
WrongCat::~WrongCat() { std::cout << getType() << " was wiped from the face of Earth"  << std::endl; }
void WrongCat::makeSound() const { std::cout << "WUFF WUFF" << std::endl; } 