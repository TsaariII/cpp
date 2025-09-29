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
#include <set>
#include <stdexcept>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <cctype>
#include <climits>
#include <ranges>

struct block {
    std::string name;
    int value;
    std::vector<int> block;
};

template<class C>
concept IntContainer =
    std::ranges::random_access_range<C> &&
    std::same_as<std::ranges::range_value_t<C>, int>;

class PmergeMe
{
  private:
    std::vector<int> _DataVec;
    std::deque<int>  _DataDeq;

    static std::string to_str(int x) {
        std::ostringstream os; os << x; return os.str();
    }
    template<IntContainer C>
    static block make_block(char kind, int pairIdx,
                            const C& v, size_t start, size_t endInclusive)
    {
        block r;
        r.name  = std::string(1, kind) + to_str(pairIdx);
        r.value = v[endInclusive]; // representative = last element
        r.block.insert(r.block.end(),
                       v.begin() + start,
                       v.begin() + endInclusive + 1);
        return r;
    }
    // Build main/pend blocks for a given p size (works for vector/deque)
    template<IntContainer C>
    static size_t build_blocks(const C& vec, size_t p, std::vector<block>& mainBlocks, std::vector<block>& pendBlocks)
    {
        mainBlocks.clear();
        pendBlocks.clear();
        const size_t n = vec.size();
        if (p == 0 || n < p) return 0;
        const size_t odd_start = n - (n % p);
        if (odd_start < 2 * p) return odd_start; // not even one full pair
        int pairIdx = 1;
        for (size_t Aend = 2 * p - 1; (Aend + 1) <= odd_start; Aend += 2 * p, ++pairIdx)
        {
            const size_t Astart = Aend - (p - 1);
            const size_t Bend   = Aend - p;
            const size_t Bstart = Bend - (p - 1);
            block bN = make_block('b', pairIdx, vec, Bstart, Bend);
            block aN = make_block('a', pairIdx, vec, Astart, Aend);
            if (pairIdx == 1) {
                mainBlocks.push_back(bN);
                mainBlocks.push_back(aN);
            } else {
                mainBlocks.push_back(aN);
                pendBlocks.push_back(bN);
            }
        }
        const size_t fullBlocks = odd_start / p;
        if (fullBlocks % 2 == 1) {
            const size_t Bstart = odd_start - p;
            const size_t Bend   = odd_start - 1;
            block bN = make_block('b', pairIdx, vec, Bstart, Bend);
            pendBlocks.push_back(bN);
        }
        return odd_start;
    }

    template<IntContainer C>
    void _Print(const std::string& label, const C& data, size_t p_size) const
    {
        std::cout << "Pair size: " << p_size << " " << label << "(" << data.size() << "): ";
        for (size_t i = 0; i < data.size(); i++)
            std::cout << " " << data[i];
        std::cout << std::endl;
    }
    // Container-agnostic sorter (your original vector logic generalized)
    template<IntContainer C>
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
            if (c[bi] < c[bi - p_size])
            {
                std::rotate(c.begin() + A0,
                            c.begin() + B0,
                            c.begin() + B0 + p_size);
            }
        }
        _Sort(c, p_size * 2);
        std::vector<block> main;
        std::vector<block> pend;
        size_t odd_s = build_blocks(c, p_size, main, pend);
        std::vector<int> odd(c.begin() + odd_s, c.end());
        struct BlockLessByValue {
            bool operator()(const block& a, const block& b) const
            {
                if (a.value != b.value) return a.value < b.value;
                return a.name < b.name;
            }
        };
        for (size_t i = pend.size(); i-- > 0; )
        {
            auto pos = std::lower_bound(main.begin(), main.end(), pend[i], BlockLessByValue());
            main.insert(pos, pend[i]);
        }
        // Flatten into a vector, then assign back to any container C
        std::vector<int> flat;
        size_t total = odd.size();
        for (size_t j = 0; j < main.size(); ++j) total += main[j].block.size();
        flat.reserve(total);
        for (size_t j = 0; j < main.size(); ++j)
            flat.insert(flat.end(), main[j].block.begin(), main[j].block.end());
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
