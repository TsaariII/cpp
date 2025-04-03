/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nzharkev <nzharkev@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 14:29:27 by nzharkev          #+#    #+#             */
/*   Updated: 2025/04/03 15:10:07 by nzharkev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Animal.hpp"

Animal::Animal() { std::cout << "Default animal was created" << std::endl; }
Animal::Animal(std::string type) : _Type(type)  { std::cout << "Created " << getType()  << std::endl; }
Animal::Animal(const Animal &copy) : _Type(copy._Type) {  std::cout << "Created copy of " << getType()  << std::endl;  }
Animal& Animal::operator=(const Animal &copy)
{
    std::cout << "Assigned " << getType()  << std::endl;
    if (this != &copy)
        _Type = copy._Type;
    return *this;
}
Animal::~Animal() { std::cout << getType() << " was wiped from the face of Earth"  << std::endl; }
std::string Animal::getType() const { return this->_Type; }
void Animal::makeSound() const { std::cout << "Generic animal sounds" << std::endl; }