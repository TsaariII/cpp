/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nzharkev <nzharkev@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 14:58:50 by nzharkev          #+#    #+#             */
/*   Updated: 2025/07/03 15:27:23 by nzharkev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"
#include <iostream>

template <typename T>
Array<T>::Array() : _Data(nullptr), _Size(0) {}

template <typename T>
Array<T>::Array(unsigned int ui) : _Data(new T[ui]), _Size(ui) {}

template <typename T>
Array<T>::Array(const Array& copy) : _Data(nullptr), _Size(copy._Size)
{
    _Data = new T[_Size];
    for (size_t i = 0; i < _Size; i++)
        _Data[i] = copy._Data[i];
}

template <typename T>
Array<T>& Array<T>::operator=(const Array& copy)
{
    if (this == &copy)
        return *this;
    _Size = copy._Size;
    _Data = new T[_Size];
    for (size_t i = 0; i < _Size; i++)
        _Data[i] = copy._Data[i];
    return *this;
}

template <typename T>
Array<T>::~Array() { delete[] _Data; }

template <typename T>
T& Array<T>::operator[](size_t indx)
{
    if (indx >= _Size)
        throw std::out_of_range("Index out of bounds");
    return _Data[indx];
}

template <typename T>
const T& Array<T>::operator[](size_t indx) const
{
    if (indx >= _Size)
        throw std::out_of_range("Index out of bounds");
    return _Data[indx];
}

template <typename T>
size_t Array<T>::size() const { return _Size; }