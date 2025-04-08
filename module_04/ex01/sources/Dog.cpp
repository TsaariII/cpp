/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nzharkev <nzharkev@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 14:52:12 by nzharkev          #+#    #+#             */
/*   Updated: 2025/04/03 15:21:44 by nzharkev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Dog.hpp"

Dog::Dog() : _Brain(new Brain) { std::cout << "Default dog was created" << std::endl; _Type = "Dog"; }
Dog::Dog(std::string type) : _Brain(new Brain) { std::cout << "Created " << getType()  << std::endl; _Type = type; }
Dog::Dog(const Dog &copy) : Animal(copy), _Brain(new Brain(*copy._Brain)) {  std::cout << "Created copy of " << getType()  << std::endl; _Type = copy._Type; }
Dog& Dog::operator=(const Dog &copy)
{
    std::cout << "Assigned " << getType()  << std::endl;
    if (this != &copy)
    {
        *_Brain = *copy._Brain;
        _Type = copy._Type;
    }
    return *this;
}
Dog::~Dog() { std::cout << getType() << " was wiped from the face of Earth"  << std::endl; delete _Brain; }

void Dog::makeSound() const { std::cout << "WUFF!! WUFF!!!" << std::endl; }

Brain* Dog::getBrain() const { return _Brain; }