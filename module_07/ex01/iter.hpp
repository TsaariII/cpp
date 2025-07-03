/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nzharkev <nzharkev@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 14:05:06 by nzharkev          #+#    #+#             */
/*   Updated: 2025/07/03 14:12:14 by nzharkev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <cstdlib>

template <typename T, typename Func> 
void iter(T *array, size_t len, Func func)
{
    for (size_t i = 0; i < len; i++)
        func(array[i]);
}