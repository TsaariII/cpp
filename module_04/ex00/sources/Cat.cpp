/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nzharkev <nzharkev@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 14:51:21 by nzharkev          #+#    #+#             */
/*   Updated: 2025/04/10 14:52:04 by nzharkev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Cat.hpp"

Cat::Cat() { std::cout << "Default cat was created" << std::endl; _Type = "Cat"; }
Cat::Cat(std::string type)  { std::cout << "Created " << getType()  << std::endl; _Type = type; }
Cat::Cat(const Cat &copy) {  std::cout << "Created copy of " << getType()  << std::endl; _Type = copy._Type; }
Cat& Cat::operator=(const Cat &copy)
{
    std::cout << "Assigned " << getType()  << std::endl;
    if (this != &copy)
        _Type = copy._Type;
    return *this;
}
Cat::~Cat() { std::cout << "Cat was wiped from the face of Earth"  << std::endl; }
void Cat::makeSound() const { std::cout << "meow" << std::endl; }