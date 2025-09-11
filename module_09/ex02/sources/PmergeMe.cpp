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
    _PrintVector("Before sorting:", _DataVec, 1);
    // _PrintDeque("Before:", _DataDeq);
    // struct timeval start, end;
    // gettimeofday(&start, NULL);
    _SortVector(_DataVec, 1);
    // gettimeofday(&end, NULL);
    // double vecTime = (end.tv_sec - start.tv_sec) * 1e6 + (end.tv_usec - start.tv_usec);
    // gettimeofday(&start, NULL);
    // _SortDeque(_DataDeq);
    // gettimeofday(&end, NULL);
    // double deqTime = (end.tv_sec - start.tv_sec) * 1e6 + (end.tv_usec - start.tv_usec);
    _PrintVector("After:", _DataVec, 1);
    // _PrintDeque("After:", _DataDeq);
    // std::cout << "Time to process a range of " << _DataVec.size()
    //           << " elements with std::vector : " << vecTime << " us" << std::endl;

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
    if (p_size == 0 || p_size * 2 > vec.size())
        return;
    // std::cout << "|===============|" << std::endl;
    const size_t step = p_size * 2;
    // {
    //     std::ostringstream os;
    //     os << "Before p_size=" << p_size << " pass: ";
    //     _PrintVector(os.str(), vec, p_size);
    // }
    size_t bi;
    if (p_size != 1)
        bi = (p_size * 2) - 1;
    else
        bi = 1;
    for (; bi < vec.size(); bi += step)
    {
        const size_t B0 = bi - (p_size -1);
        const size_t A0 = B0 - p_size;
        if (vec[bi] < vec[bi - p_size])
        {
            // std::cout << "bi = " << bi << std::endl;
            std::rotate(vec.begin() + A0,
                        vec.begin() + B0,
                        vec.begin() + B0 + p_size);
            // _PrintVector("After rotate swap: ", vec, p_size);
        }
    }
    // {
    //     std::ostringstream os;
    //     os << "After  p_size=" << p_size << " pass: ";
    //     _PrintVector(os.str(), vec, p_size);
    // }
    _SortVector(vec, p_size * 2);
    std::cout << "|===============|" << std::endl;
    std::cout << "Pair size: " << p_size << std::endl;
    _PrintVector("Before Jacobstahl:", vec, p_size);
    std::vector<block> main_s;
    std::vector<block> pend_s;
    std::vector<int> main;
    std::vector<int> pend;
    size_t i = 0;
    for (; i < (p_size * 2); i++)
        main.push_back(vec[i]);
    for (; i < vec.size(); i++)
    {
        if (i + p_size > vec.size())
         break;
        main.push_back(vec[i + p_size]);
        pend.push_back(vec[i]);
    }
    int pair = 0;
    
    // for (size_t i = p_size * 2 - 1; i < vec.size(); i += p_size * 2)
    // {
        //     if (i + p_size > vec.size())
        //         break;
        //     // std::cout << "i: " << std::to_string(i - p_size) << std::endl;
        //     pair += 1;
        //     block b;
        //     b.value = main[i - p_size];
        //     b.name = "b" + std::to_string(pair);
        //     size_t k = i - (p_size * 2);
        //     if (k > main.size())
        //         k = 0;
        //     for (; k < p_size; k++)
        //         b.block.push_back(main[k]);
        //     block a;
        //     a.value = main[i];
        //     a.name = "a" + std::to_string(pair);
        //     // std::cout << "i: " << std::to_string(i - p_size) << std::endl;
        //     for (size_t j = i - p_size + 1; j <= i; j++)
        //         a.block.push_back(main[j]);
        //     if (pair == 1)
        //     {
        //         main_s.push_back(b);
        //         main_s.push_back(a);
        //     }
        //     else
        //     {
        //         main_s.push_back(a);
        //         pend_s.push_back(b);
        //     }
        // }
    // std::cout << "p_size * 2 - 1 = " << std::to_string(p_size * 2 - 1) << std::endl;
    // std::cout << "main size: " << std::to_string(main.size()) << std::endl;
    for (size_t i = p_size * 2 - 1; i < main.size(); i += p_size * 2)
    {
        // std::cout << "i: " << std::to_string(i) << std::endl;
        if (i + p_size > vec.size() && pair != 1)
            break;
        block a;
        block b;
        pair += 1;
        if (pair == 1)
        {
            b.value = main[i - p_size];
            b.name = "b" + std::to_string(pair);
            size_t k = i - (p_size * 2);
            if (k > main.size())
                k = 0;
            for (; k < p_size; k++)
                b.block.push_back(main[k]);
            a.value = main[i];
            a.name = "a" + std::to_string(pair);
            for (size_t j = i - p_size + 1; j <= i; j++)
                a.block.push_back(main[j]);
            main_s.push_back(b);
            main_s.push_back(a);
        }
        else
        {
            a.value = main[i];
            a.name = "a" + std::to_string(pair);
            // std::cout << "i: " << std::to_string(i - p_size) << std::endl;
            for (size_t j = i - p_size + 1; j <= i; j++)
                a.block.push_back(main[j]);
            main_s.push_back(a);
        }
    }
    for (size_t i = p_size - 1; i < pend.size(); i += p_size)
    {
        // std::cout << "i: " << std::to_string(i) << std::endl;
        block b;
        b.value = pend[i];
        b.name = "b" + std::to_string(pair);
        size_t k = i - p_size + 1;
        if (k > pend.size())
            k = 0;
        for (; k <= i; k++)
            b.block.push_back(pend[k]);
        pend_s.push_back(b);
        pair += 1;
    }
    struct BlockLessByValue {
        bool operator()(const block& a, const block& b) const {
            if (a.value != b.value) return a.value < b.value;
            return a.name < b.name;
        }
    };
    for (size_t i = pend_s.size() - 1; i < pend_s.size(); i--)
    {
        std::vector<block>::iterator pos = std::lower_bound(main_s.begin(), main_s.end(), pend_s[i], BlockLessByValue());
        main_s.insert(pos, pend_s[i]);
    }
    main.clear();
    for (size_t i = 0; i < main_s.size(); i++)
    {
        for (size_t j = 0; j < main_s[i].block.size(); j++)
            main.push_back(main_s[i].block[j]);
    }
    _PrintVector("Main:", main, p_size);
    // std::cout << "Main_s:\n";
    // for (size_t i = 0; i < main_s.size(); i++)
    // {
    //    std::cout << "name: " << main_s[i].name\
    //     << "\nvalue: " << main_s[i].value\
    //     << "\nblock: ";
    //     for (size_t j = 0; j < main_s[i].block.size(); j++)
    //     std::cout << main_s[i].block[j] << " ";
    //     std::cout << "\n\t||||||||" << std::endl;
    // }
    _PrintVector("Pend:", pend, p_size);
    // std::cout << "Pend_s:\n";
    // for (size_t i = 0; i < pend_s.size(); i++)
    // {
    //    std::cout << "name: " << pend_s[i].name\
    //     << "\nvalue: " << pend_s[i].value\
    //     << "\nblock: ";
    //     for (size_t j = 0; j < pend_s[i].block.size(); j++)
    //         std::cout << pend_s[i].block[j] << " ";
    //     std::cout << "\n\t||||||||" << std::endl;
    // }
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
        i = p_size - 1;
    else
    {
        i = 1;
        step = 1;
    }
    size_t j = i - p_size;
    if (p_size != 1)
        j = 0;
    for (; i < data.size(); i += p_size)
    {
        std::cout << "{";
        if (p_size == 1)
        {
            for (; j < i; j++)
            {;
                std::cout << data[j];
                if (j != i - 1 && step != 1)
                    std::cout << " ";
            }
        }
        else
        {
            for (; j <= i; j++)
            {
                std::cout << data[j];
                if (j != i && step != 1)
                    std::cout << " ";
            }
        }
        std::cout << "} ";
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