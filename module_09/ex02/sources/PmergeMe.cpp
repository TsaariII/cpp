/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                            :+:      :+:    :+:   */
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
            if(!isdigit(arg[j]))
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
    _PrintVector("Before:", _DataVec);
    _PrintDeque("Before:", _DataDeq);
    struct timeval start, end;
    gettimeofday(&start, NULL);
    _SortVector(_DataVec);
    gettimeofday(&end, NULL);
    double vecTime = (end.tv_sec - start.tv_sec) * 1e6 + (end.tv_usec - start.tv_usec);
    gettimeofday(&start, NULL);
    _SortDeque(_DataDeq);
    gettimeofday(&end, NULL);
    double deqTime = (end.tv_sec - start.tv_sec) * 1e6 + (end.tv_usec - start.tv_usec);
    _PrintVector("After:", _DataVec);
    _PrintDeque("After:", _DataDeq);
    std::cout << "Time to process a range of " << _DataVec.size()
              << " elements with std::vector : " << vecTime << " us" << std::endl;

    std::cout << "Time to process a range of " << _DataDeq.size()
              << " elements with std::deque : " << deqTime << " us" << std::endl;
}

std::vector<size_t> generateJacobsthal(size_t size)
{
    std::vector<size_t> seq;
    std::vector<bool> used(size, false);
    size_t j0 = 0;
    size_t j1 = 1;
    if (size == 0)
        return seq;
    if (j1 < size)
    {
        seq.push_back(j1);
        used[j1] = true;
    }
    while (true)
    {
        size_t jn = j1 + 2 * j0;
        if (jn >= size)
            break;
        seq.push_back(jn);
        used[jn] = true;
        j0 = j1;
        j1 = jn;
    }
    for (size_t i = 0; i < size; i++)
    {
        if (!used[i])
            seq.push_back(i);
    }
    return seq;
}


void PmergeMe::_SortVector(std::vector<int>& vec)
{
    if (vec.size() <= 1)
        return;
    std::vector<int> main;
    std::vector<int> pend;
    size_t i = 0;
    for (; i + 1 < vec.size(); i += 2)
    {
        int a = vec[i];
        int b = vec[i + 1];
        if (a < b)
        {
            pend.push_back(a);
            main.push_back(b);
        }
        else
        {
            pend.push_back(b);
            main.push_back(a);
        }
    }
    bool odd = (i < vec.size());
    int last = odd ? vec.back() : -1;
    _SortVector(main);
    std::vector<size_t> insertionOrder = generateJacobsthal(pend.size());
    for (size_t j = 0; j < insertionOrder.size(); ++j)
    {
        size_t indx = insertionOrder[j];
        std::vector<int>::iterator pos = std::lower_bound(main.begin(), main.end(), pend[indx]);
        main.insert(pos, pend[indx]);
    }
    if (odd)
    {
        std::vector<int>::iterator pos = std::lower_bound(main.begin(), main.end(), last);
        main.insert(pos, last); 
    }
    vec = main;
}

void PmergeMe::_SortDeque(std::deque<int>& deq)
{
    if (deq.size() <= 1)
        return;
    std::deque<int> main;
    std::deque<int> pend;
    size_t i = 0;
    for (; i + 1 < deq.size(); i += 2)
    {
        int a = deq[i];
        int b = deq[i + 1];
        if (a < b)
        {
            pend.push_back(a);
            main.push_back(b);
        }
        else
        {
            pend.push_back(b);
            main.push_back(a);
        }
    }
    bool odd = (i < deq.size());
    int last = odd ? deq.back() : -1;
    _SortDeque(main);
    std::vector<size_t> insertionOrder = generateJacobsthal(pend.size());
    for (size_t j = 0; j < insertionOrder.size(); ++j)
    {
        size_t indx = insertionOrder[j];
        std::deque<int>::iterator pos = std::lower_bound(main.begin(), main.end(), pend[indx]);
        main.insert(pos, pend[indx]);
    }
    if (odd)
    {
        std::deque<int>::iterator pos = std::lower_bound(main.begin(), main.end(), last);
        main.insert(pos, last); 
    }
    deq = main;
}

void PmergeMe::_PrintVector(const std::string& label, const std::vector<int>& data)
{
    std::cout << label;
    for (size_t i = 0; i < data.size(); i++)
        std::cout << " " << data[i];
    std::cout << std::endl;

}

void PmergeMe::_PrintDeque(const std::string& label, const std::deque<int>& data)
{
    std::cout << label;
    for (size_t i = 0; i < data.size(); i++)
        std::cout << " " << data[i];
    std::cout << std::endl;
}