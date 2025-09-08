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
    _PrintVector("Before:", _DataVec, 1);
    // _PrintDeque("Before:", _DataDeq);
    struct timeval start, end;
    gettimeofday(&start, NULL);
    _SortVector(_DataVec, 1);
    gettimeofday(&end, NULL);
    double vecTime = (end.tv_sec - start.tv_sec) * 1e6 + (end.tv_usec - start.tv_usec);
    // gettimeofday(&start, NULL);
    // _SortDeque(_DataDeq);
    // gettimeofday(&end, NULL);
    // double deqTime = (end.tv_sec - start.tv_sec) * 1e6 + (end.tv_usec - start.tv_usec);
    // _PrintVector("After:", _DataVec);
    // _PrintDeque("After:", _DataDeq);
    std::cout << "Time to process a range of " << _DataVec.size()
              << " elements with std::vector : " << vecTime << " us" << std::endl;

    // std::cout << "Time to process a range of " << _DataDeq.size()
    //           << " elements with std::deque : " << deqTime << " us" << std::endl;
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


void PmergeMe::_SortVector(std::vector<int>& vec, size_t p_size)
{
    if (p_size == 0 || p_size >= vec.size()) {
        // base case: nothing to do / one p_size covers all
        std::ostringstream base;
        base << "Base (p_size = " << p_size << "): ";
        _PrintVector(base.str(), vec, p_size);
        return;
    }

    std::cout << "p_size = " << p_size << std::endl;
    const size_t step = p_size * 2;
    size_t bi;
    if (p_size != 1)
        bi = 1 + p_size;
    else
        bi = 1;
    std::cout << "|===============|" << std::endl;
    for (; bi < vec.size(); bi += step)
    {
        // std::cout << "bi = " << bi << std::endl;
        const size_t a = bi;// + p_size;  // start of p_size A
        const size_t b = (bi - p_size);// + p_size;        // start of p_size B (adjacent to A)
        // std::cout << "a = " << a << ": " << vec[a] << " b = " << b << ": " << vec[b] << std::endl;
        // Compare by first element of each p_size
        if (vec[a] < vec[b])
        {
            // std::cout << "Pair to swap {" << vec[a] << " " << vec[b] << "}" << std::endl;
            std::swap_ranges(vec.begin() + b, vec.begin() + a, vec.begin() + b + p_size);
        }
    }
    std::cout << "|===============|" << std::endl;
    std::ostringstream pass;
    pass << "After p_size=" << p_size << " swap: ";
    _PrintVector(pass.str(), vec, p_size);

    // Recurse doubling the p_size size
    _SortVector(vec, p_size * 2);
}

void PmergeMe::_SortDeque(std::deque<int>& deq)
{
    std::cout << deq[0] << std::endl;
}

void PmergeMe::_PrintVector(const std::string& label, const std::vector<int>& data, size_t p_size)
{
    std::cout << label;
    size_t step = p_size * 2;
    size_t i;
    if (p_size != 1)
        i =  + step;// 0 + p_size;
    else
    {
        i = 1;
        step = 1;
    }
    for (; i < data.size(); i += step)
    {
        size_t j;
        if (i != 1 + p_size)
            j = i - (p_size * 2);
        else
            j = 0;
        std::cout << "{";
        for (; j < i; j++)
        {
            std::cout << data[j];
            if (j != i - 1 && step != 1)
                std::cout << " ";
            if ((j == j + step) && j < i)
                std::cout << "}{";
        }
        std::cout << "}";
    }
    std::cout << std::endl;

}

void PmergeMe::_PrintDeque(const std::string& label, const std::deque<int>& data)
{
    std::cout << label;
    for (size_t i = 0; i < data.size(); i++)
        std::cout << " " << data[i];
    std::cout << std::endl;
}