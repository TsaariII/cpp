/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nzharkev <nzharkev@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 14:52:12 by nzharkev          #+#    #+#             */
/*   Updated: 2025/04/10 14:52:14 by nzharkev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Dog.hpp"

Dog::Dog() { std::cout << "Default dog was created" << std::endl; _Type = "Dog"; }
Dog::Dog(std::string type) { std::cout << "Created " << getType()  << std::endl; _Type = type; }
Dog::Dog(const Dog &copy) {  std::cout << "Created copy of " << getType()  << std::endl; _Type = copy._Type; }
Dog& Dog::operator=(const Dog &copy)
{
    std::cout << "Assigned " << getType()  << std::endl;
    if (this != &copy)
        _Type = copy._Type;
    return *this;
}
Dog::~Dog() { std::cout << "Dog was wiped from the face of Earth"  << std::endl; }
void Dog::makeSound() const { std::cout << "WUFF!! WUFF!!!" << std::endl; }