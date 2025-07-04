/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nzharkev <nzharkev@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 13:12:32 by nzharkev          #+#    #+#             */
/*   Updated: 2025/07/04 13:46:21 by nzharkev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <algorithm>
#include <deque>
#include <stack>

template <typename T, typename Container = std::deque<T> >
class MutantStack: public std::stack<T, Container>
{
    public:
        MutantStack() {};
        MutantStack(const MutantStack& copy) : std::stack<T>(copy) {};
        MutantStack& operator=(const MutantStack& copy)
        {
            if (this != &copy)
                std::stack<T>::operator=(copy);
            return *this;
        }
        ~MutantStack() {};
        typedef typename Container::iterator iterator;       
        typedef typename Container::const_iterator const_iterator;
        typedef typename Container::reverse_iterator reverse_iterator;
        typedef typename Container::const_reverse_iterator const_reverse_iterator;

        iterator begin() { return this->c.begin(); };
        iterator end() { return this->c.end(); }
        const_iterator cbegin() { return this->c.begin(); };
        const_iterator cend() { return this->c.end(); };
        reverse_iterator rbegin() { return this->c.rbegin(); };
        reverse_iterator rend() { return this->c.rend(); };
        const_reverse_iterator crbegin() { return this->c.rbegin(); };
        const_reverse_iterator crend() { return this->c.rend(); };      
};