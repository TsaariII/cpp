/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nzharkev <nzharkev@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 14:29:27 by nzharkev          #+#    #+#             */
/*   Updated: 2025/04/03 15:10:07 by nzharkev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/WrongAnimal.hpp"

WrongAnimal::WrongAnimal() { std::cout << "Default wrong animal was created" << std::endl; }
WrongAnimal::WrongAnimal(std::string type) : _Type(type)  { std::cout << "Created " << getType()  << std::endl; }
WrongAnimal::WrongAnimal(const WrongAnimal &copy) : _Type(copy._Type) {  std::cout << "Created copy of " << getType()  << std::endl;  }
WrongAnimal& WrongAnimal::operator=(const WrongAnimal &copy)
{
    std::cout << "Assigned " << getType()  << std::endl;
    if (this != &copy)
        _Type = copy._Type;
    return *this;
}
WrongAnimal::~WrongAnimal() { std::cout << "WrongAnimal was wiped from the face of Earth"  << std::endl; }
std::string WrongAnimal::getType() const { return this->_Type; }
void WrongAnimal::makeSound() const { std::cout << "Generic WrongAnimal sounds" << std::endl; }