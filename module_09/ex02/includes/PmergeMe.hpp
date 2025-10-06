/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
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
#include <set>
#include <stdexcept>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <cctype>
#include <climits>
#include <ranges>

template<typename C>
struct block {
    using container_type = C;
    std::string name;
    int value;
    container_type block;
};

class PmergeMe
{
  private:
    std::vector<int> _DataVec;
    std::deque<int>  _DataDeq;
    static int comparisons;

    template<typename C, typename NewT>
    struct rebind_container;

    template<template<class, class>  class Cont,class OldT, class OldAlloc, class NewT>
    struct rebind_container<Cont<OldT, OldAlloc>, NewT> {
    using type = Cont<NewT,
        typename std::allocator_traits<OldAlloc>::template rebind_alloc<NewT>>;
    };

    template<typename C>
    static block<C> make_block(char kind, int pairIdx, const C& v, size_t start, size_t endInclusive)
    {
        block<C> r;
        r.name  = std::string(1, kind) + std::to_string(pairIdx);
        r.value = v[endInclusive];
        r.block.insert(r.block.end(), v.begin() + start, v.begin() + endInclusive + 1);
        return r;
    }

    template<typename C>
    static size_t build_blocks(const C& vec, size_t p, typename rebind_container<C, block<C>>::type& main, typename rebind_container<C, block<C>>::type& pend)
    {
        main.clear();
        pend.clear();
        const size_t n = vec.size();
        if (p == 0 || n < p) return 0;
        const size_t odd_start = n - (n % p);
        if (odd_start < 2 * p) return odd_start;
        int pairIdx = 1;
        for (size_t Aend = 2 * p - 1; (Aend + 1) <= odd_start; Aend += 2 * p, ++pairIdx)
        {
            const size_t Astart = Aend - (p - 1);
            const size_t Bend   = Aend - p;
            const size_t Bstart = Bend - (p - 1);
            block bN = make_block('b', pairIdx, vec, Bstart, Bend);
            block aN = make_block('a', pairIdx, vec, Astart, Aend);
            if (pairIdx == 1) {
                main.push_back(bN);
                main.push_back(aN);
            } else {
                main.push_back(aN);
                pend.push_back(bN);
            }
        }
        const size_t fullBlocks = odd_start / p;
        if (fullBlocks % 2 == 1) {
            const size_t Bstart = odd_start - p;
            const size_t Bend   = odd_start - 1;
            block<C> bN = make_block('b', pairIdx, vec, Bstart, Bend);
            pend.push_back(bN);
        }
        return odd_start;
    }

    template<typename C>
    void _Print(const std::string& label, const C& data) const
    {
        std::cout << label;
        for (size_t i = 0; i < data.size(); i++)
            std::cout << " " << data[i];
        std::cout << std::endl;
    }

    template<typename C>
    void _Sort(C& c, size_t p_size)
    {
        if (p_size == 0 || p_size * 2 > c.size())
            return;
        const size_t step = p_size * 2;
        size_t bi = (p_size != 1) ? (p_size * 2) - 1 : 1;
        for (; bi < c.size(); bi += step)
        {
            const size_t B0 = bi - (p_size - 1);
            const size_t A0 = B0 - p_size;
            comparisons++;
            if (c[bi] < c[bi - p_size])
                std::rotate(c.begin() + A0, c.begin() + B0, c.begin() + B0 + p_size);
        }
        _Sort(c, p_size * 2);
        using BlockT = block<C>;
        using ContBlock = typename rebind_container<C, BlockT>::type;
        ContBlock main;
        ContBlock pend;
        const size_t odd_s = build_blocks(c, p_size, main, pend);
        C odd;
        odd.insert(odd.end(), c.begin() + odd_s, c.end());
        auto build_jacobsthal_order = [](std::size_t pendCount) {
            const std::size_t firstLabel = 2;
            const std::size_t lastLabel  = firstLabel + (pendCount ? pendCount - 1 : 0);
            std::vector<std::size_t> labels;
            if (pendCount == 0) return labels;
            std::size_t prevJ = 1, curJ  = 3;
            while (curJ <= lastLabel) {
                for (std::size_t L = curJ; L > prevJ; --L) {
                    if (L >= firstLabel) labels.push_back(L);
                }
                const std::size_t nextJ = curJ + 2 * prevJ;
                prevJ = curJ;
                curJ  = nextJ;
            }
            for (std::size_t L = lastLabel; L > prevJ; --L) {
                if (L >= firstLabel) labels.push_back(L);
            }
            return labels;
        };
        const auto labels = build_jacobsthal_order(pend.size());
        auto find_bound_after_a = [&](std::size_t L) -> typename ContBlock::iterator {
            const std::string aName = "a" + std::to_string(static_cast<int>(L));
            for (auto it = main.begin(); it != main.end(); ++it) {
                if (it->name == aName) {
                    return std::next(it);
                }
            }
            return main.end();
        };
        auto cmp = [this](const auto& a, const auto& b){
            this->comparisons++;
            if (a.value != b.value) return a.value < b.value;
            return a.name < b.name;
        };
        for (std::size_t li = 0; li < labels.size(); ++li) {
            const std::size_t L = labels[li];
            if (L < 2) continue;
            const std::size_t idx = L - 2;
            if (idx >= pend.size())
                continue;
            auto boundEnd = find_bound_after_a(L);
            if (boundEnd == main.begin()) {
                main.insert(main.begin(), pend[idx]);
                continue;
            }
            if (boundEnd == main.end())
            {
                comparisons++;
                main.insert(main.end(), std::move(pend[idx]));
            }
            else
            {
                auto pos = std::lower_bound(main.begin(), boundEnd, pend[idx], cmp);
                main.insert(pos, std::move(pend[idx]));
            }
        }
        C flat;
        if constexpr (requires(C x, std::size_t n){x.reserve(n);}){
            std::size_t total = odd.size();
            for (const auto& b : main) total += b.block.size();
            flat.reserve(total);
        }
        for(const auto& b : main)
            flat.insert(flat.end(), b.block.begin(), b.block.end());
        flat.insert(flat.end(), odd.begin(), odd.end());
        c.assign(flat.begin(), flat.end());
    }

  public:
    PmergeMe();
    PmergeMe(const PmergeMe& copy);
    PmergeMe& operator=(const PmergeMe& copy);
    ~PmergeMe();

    void readInput(char **argv);
    void sorter();
};

