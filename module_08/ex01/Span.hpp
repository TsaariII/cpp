/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nzharkev <nzharkev@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 16:24:05 by nzharkev          #+#    #+#             */
/*   Updated: 2025/07/03 17:42:40 by nzharkev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <vector>

class Span
{
    private:
        unsigned int _Max;
        std::vector<int> _Ints;
    public:
        Span();
        Span(unsigned int N);
        Span(const Span& copy);
        Span& operator=(const Span& copy);
        ~Span();
        void addNumber(int num);
        int shortestSpan() const;
        int longestSpan() const;
        void addRange(std::vector<int>::iterator first, std::vector<int>::iterator last);
};