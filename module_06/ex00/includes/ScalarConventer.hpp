/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConventer.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nzharkev <nzharkev@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 12:07:47 by nzharkev          #+#    #+#             */
/*   Updated: 2025/05/01 12:44:29 by nzharkev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <string>

enum Types
{
    CHAR,
    INT,
    FLOAT,
    DOUBLE,
    SPECIAL,
    INVALID,
};

class ScalarConverter
{
    private:
        ScalarConverter();
        ScalarConverter(const ScalarConverter& ref);
        ScalarConverter& operator=(const ScalarConverter& ref);
        ~ScalarConverter();
    public:
        static void convert(const std::string& lit);
           
};