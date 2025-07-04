/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nzharkev <nzharkev@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 16:31:58 by nzharkev          #+#    #+#             */
/*   Updated: 2025/07/04 12:55:57 by nzharkev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <iostream>

Span::Span() : _Max(0) {}

Span::Span(unsigned int N) : _Max(N) {}

Span::Span(const Span& copy)
{
    if (this != &copy)
    {
        _Max = copy._Max;
        _Ints = copy._Ints;   
    }
}

Span& Span::operator=(const Span& copy)
{
    if (this != &copy)
    {
        _Max = copy._Max;
        _Ints = copy._Ints;           
    }
    return *this;
}

Span::~Span() {}

void Span::addNumber(int num)
{
    if (_Ints.size() >= _Max)
        throw std::runtime_error("Can't add. Capacity full");
    else
        _Ints.push_back(num);
}

int Span::shortestSpan() const
{
    if (_Ints.size() <= 2)
        throw std::runtime_error("Not enough elements to compute span");
    std::vector<int> copy = _Ints;
    std::sort(copy.begin(), copy.end());
    int minSpan = std::numeric_limits<int>::max();
    for (size_t i = 1; i < copy.size(); i++)
    {
        int span = copy[i] - copy[i - 1];
        if (span < minSpan)
            minSpan = span;
    }
    return minSpan;
}

int Span::longestSpan() const
{
    if (_Ints.size() <= 2)
    throw std::runtime_error("Not enough elements to compute span");
    int minVal = *std::min_element(_Ints.begin(), _Ints.end());
    int maxVal = *std::max_element(_Ints.begin(), _Ints.end());
    return maxVal - minVal;
}

void Span::addRange(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
    size_t range = std::distance(begin, end);
    if (_Ints.size() + range  > _Max)
        throw std::runtime_error("Cannot add elements: capacity exceeded");
    _Ints.insert(_Ints.end(), begin, end);
}