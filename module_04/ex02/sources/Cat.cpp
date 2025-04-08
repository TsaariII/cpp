/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nzharkev <nzharkev@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 14:51:21 by nzharkev          #+#    #+#             */
/*   Updated: 2025/04/03 15:20:23 by nzharkev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Cat.hpp"

Cat::Cat() : _Brain(new Brain) { std::cout << "Default cat was created" << std::endl; _Type = "Cat"; }

Cat::Cat(std::string type) : _Brain(new Brain) { std::cout << "Created " << getType()  << std::endl; _Type = type; }

Cat::Cat(const Cat &copy) : Animal(copy), _Brain(new Brain(*copy._Brain)) {  std::cout << "Created copy of " << getType()  << std::endl; _Type = copy._Type; }

Cat& Cat::operator=(const Cat &copy)
{
    std::cout << "Assigned " << getType()  << std::endl;
    if (this != &copy)
    {
        *_Brain = *copy._Brain;
        _Type = copy._Type;
    }
    return *this;
}

Cat::~Cat() { std::cout << getType() << " was wiped from the face of Earth"  << std::endl; delete _Brain; }

void Cat::makeSound() const { std::cout << "meow" << std::endl; }

Brain* Cat::getBrain() const { return _Brain; }