/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nzharkev <nzharkev@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 10:39:53 by nzharkev          #+#    #+#             */
/*   Updated: 2025/07/14 14:48:02 by nzharkev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/PmergeMe.hpp"
#include <sys/time.h>
#include <algorithm>
#include <cctype>
#include <set>
#include <cstdint>

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe& copy) : _DataVec(copy._DataVec), _DataDeq(copy._DataDeq) {}

PmergeMe& PmergeMe::operator=(const PmergeMe& copy)
{
    if (this != &copy)
    {
        _DataVec = copy._DataVec;
        _DataDeq = copy._DataDeq;
    }
    return *this;
}

PmergeMe::~PmergeMe() {}

void PmergeMe::readInput(char **argv)
{
    std::set<long> seen;
    for (int i = 0; argv[i]; i++)
    {
        std::string arg(argv[i]);
        for (size_t j = 0; j < arg.length(); j++)
        {
            if (!std::isdigit(static_cast<unsigned char>(arg[j])))
                throw std::invalid_argument("Non-digit character found");
        }
        long value = std::strtol(arg.c_str(), NULL, 10);
        if (value < 0 || value > INT32_MAX)
            throw std::invalid_argument("Invalid number");
        if (!seen.insert(value).second)
            throw std::runtime_error("Duplicate number");
        _DataVec.push_back(static_cast<int>(value));
        _DataDeq.push_back(static_cast<int>(value));
    }
}

void PmergeMe::sorter()
{
    _Print("Before sorting ", _DataVec, 1);
    struct timeval start, end;
    gettimeofday(&start, NULL);
    _Sort(_DataVec, 1);
    gettimeofday(&end, NULL);
    double vecTime = (end.tv_sec - start.tv_sec) * 1e6 + (end.tv_usec - start.tv_usec);
    gettimeofday(&start, NULL);
    _Sort(_DataDeq, 1);
    gettimeofday(&end, NULL);
    double deqTime = (end.tv_sec - start.tv_sec) * 1e6 + (end.tv_usec - start.tv_usec);
    _Print("After ", _DataVec, 1);
    std::cout << "Time to process a range of " << _DataVec.size()
              << " elements with std::vector : " << vecTime << " us" << std::endl;

    std::cout << "Time to process a range of " << _DataDeq.size()
              << " elements with std::deque : " << deqTime << " us" << std::endl;
}
