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

    template<IntContainer C>
    static block make_block(char kind, int pairIdx, const C& v, size_t start, size_t endInclusive)
    {
        block r;
        r.name  = std::string(1, kind) + std::to_string(pairIdx);
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
                std::rotate(c.begin() + A0, c.begin() + B0, c.begin() + B0 + p_size);
        }
        _Sort(c, p_size * 2);
        std::vector<block> main;
        std::vector<block> pend;
        size_t odd_s = build_blocks(c, p_size, main, pend);
        std::vector<int> odd(c.begin() + odd_s, c.end());
        // --- Jacobsthal-guided insertion of pend into main ---
        // 1) Build insertion order as labels (not indices): batches like [3,2], [5,4], [11..6], ...
        auto build_jacobsthal_order = [](std::size_t pendCount) {
            // pend holds b2..bK where K = pendCount + 1
            const std::size_t firstLabel = 2;
            const std::size_t lastLabel  = firstLabel + (pendCount ? pendCount - 1 : 0);

            std::vector<std::size_t> labels;
            if (pendCount == 0) return labels;
            // Jacobsthal sequence variant we need: 1, 3, 5, 11, 21, 43, ...
            // Start with prevJ = 1, curJ = 3
            std::size_t prevJ = 1;
            std::size_t curJ  = 3;
            // Emit batches while the current Jacobsthal is within our label range
            while (curJ <= lastLabel) {
                for (std::size_t L = curJ; L > prevJ; --L) {
                    if (L >= firstLabel) labels.push_back(L);
                }
                // nextJ = curJ + 2*prevJ
                const std::size_t nextJ = curJ + 2 * prevJ;
                prevJ = curJ;
                curJ  = nextJ;
            }
            // Any remaining labels after the last full Jacobsthal batch
            for (std::size_t L = lastLabel; L > prevJ; --L) {
                if (L >= firstLabel) labels.push_back(L);
            }

            return labels; // decreasing label order already
        };
        const auto labels = build_jacobsthal_order(pend.size());
        // 2) For each label L, insert bL (which is pend[L-2]) into main using a bounded binary search
        auto find_bound_after_a = [&](std::size_t L) -> std::vector<block>::iterator {
            // We search up to and including the matching aL. If not found, return main.end()
            const std::string aName = "a" + std::to_string(static_cast<int>(L));
            for (auto it = main.begin(); it != main.end(); ++it) {
                if (it->name == aName) {
                    return std::next(it); // search range is [main.begin(), it] inclusive -> end = it+1
                }
            }
            return main.end(); // fallback: no bound found, search entire main
        };
        struct BlockLessByValue {
            bool operator()(const block& a, const block& b) const {
                if (a.value != b.value) return a.value < b.value;
                return a.name < b.name;
            }
        };
        for (std::size_t li = 0; li < labels.size(); ++li) {
            const std::size_t L = labels[li];
            // Map label to pend index; guard against partially filled last batch
            if (L < 2) continue; // we never store b1 in pend
            const std::size_t idx = L - 2;
            if (idx >= pend.size())
                continue; // not present, skip
            // Bound the search window to end just after aL, if aL exists
            auto boundEnd = find_bound_after_a(L);
            if (boundEnd == main.begin()) {
                // Nothing to search against, just insert at begin
                main.insert(main.begin(), pend[idx]);
                continue;
            }
            auto pos = std::lower_bound(main.begin(), boundEnd, pend[idx], BlockLessByValue());
            main.insert(pos, pend[idx]);
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
