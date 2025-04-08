/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nzharkev <nzharkev@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-04-07 11:14:21 by nzharkev          #+#    #+#             */
/*   Updated: 2025-04-07 11:14:21 by nzharkev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Brain.hpp"

Brain::Brain()
{
    std::cout << "Brain constructed" << std::endl;
    // for (int i = 0; i < 100; i++)
    //     ideas[i] = "This is the deafault ideas that animal has";
}

Brain::Brain(const Brain &copy)
{ 
    std::cout << "Copy of brain constructed" << std::endl;
    for (int i = 0; i < 100; i++)
        ideas[i] = copy.ideas[i];
}

Brain& Brain::operator=(const Brain &copy)
{
    std::cout << "Assigned copy of brain constructed" << std::endl;
    if (this != &copy)
    {
        for (int i = 0; i < 100; i++)
            ideas[i] = copy.ideas[i];
    }
    return *this;
}
Brain::~Brain() { std::cout << "Brain destroyed" << std::endl; }

const std::string& Brain::getIdea(int i) const { return ideas[i]; }

void Brain::setIdea(int i, const std::string& idea) { ideas[i] = idea; }