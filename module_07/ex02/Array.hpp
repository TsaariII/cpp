/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nzharkev <nzharkev@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 14:52:24 by nzharkev          #+#    #+#             */
/*   Updated: 2025/07/03 15:18:08 by nzharkev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <cstddef>
#include <exception>

template <typename T>
class Array
{
    private:
        T* _Data;
        size_t _Size;
    public:
        Array();
        Array(unsigned int ui);
        Array(const Array& copy);
        Array& operator=(const Array& copy);
        ~Array();
        T& operator[](size_t indx);
        const T& operator[](size_t indx) const;
        size_t size() const;
};

#include "Array.tpp"