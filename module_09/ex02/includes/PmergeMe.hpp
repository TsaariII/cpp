/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nzharkev <nzharkev@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 14:10:33 by nzharkev          #+#    #+#             */
/*   Updated: 2025/07/14 14:36:29 by nzharkev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <vector>
#include <deque>
#include <string>
#include <iostream>
#include <cstdlib>
#include <stdexcept>
#include <sstream>

struct block
{
    std::string name;
    int value;
    std::vector<int> block;
};


class PmergeMe
{
    private:
        std::vector<int> _DataVec;
        std::deque<int> _DataDeq;
        void _SortVector(std::vector<int>& vec, size_t p_size);
        void _SortDeque(std::deque<int>& deq);
        void _PrintVector(const std::string& label, const std::vector<int>& data, size_t p_size);
        void _PrintDeque(const std::string& label, const std::deque<int>& data);
    public:
        PmergeMe();
        PmergeMe(const PmergeMe& copy);
        PmergeMe& operator=(const PmergeMe& copy);
        ~PmergeMe();
        void readInput(char **argv);
        void sorter();
};