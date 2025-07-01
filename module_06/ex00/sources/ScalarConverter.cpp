/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nzharkev <nzharkev@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 13:02:03 by nzharkev          #+#    #+#             */
/*   Updated: 2025/05/01 13:02:24 by nzharkev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ScalarConventer.hpp"
#include <iostream>
// #include <cstdlib>
// #include <cctype>
#include <cmath>
// #include <limits>
// #include <sstream>

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter& ref) { static_cast<void>(ref); }

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& ref) { static_cast<void>(ref); }

ScalarConverter::~ScalarConverter() {}

static bool isChar(const std::string& c)
{
    return c.length() == 1 && !std::isdigit(c[0]);
}

static bool isInt(const std::string& c)
{
    char* end;
    std::strtol(c.c_str(), &end, 10);
    return *end == '\0';
}

static bool isFloat(const std::string& c)
{
    if (c == "+inff" || c == "-inff" || c == "nanf")
        return true;
    char *end;
    std::strtof(c.c_str(), &end);
    return *end == 'f' && *(end + 1) == '\0';
}

static bool  isDouble(const std::string& c)
{
    if (c == "+inff" || c == "-inff" || c == "nanf")
        return true;
    char *end; 
    std::strtod(c.c_str(), &end);
    return *end == '\0';
}

void ScalarConverter::convert(const std::string& lit) 
{
    try
    {
        if (isChar(lit))
        {
            char c = lit[0];
            std::cout << "char: " << c << "\n";
            std::cout << "int: " << static_cast<int>(c) << "\n";
            std::cout << "float: " << static_cast<float>(c) << "f\n";
            std::cout << "double: " << static_cast<double>(c) << "\n";
        }
        else if (isInt(lit))
        {
            int i = std::stoi(lit);
            char c = static_cast<char>(i);
            if (std::isprint(c))
                std::cout << "char: " << c << "\n";
            else
                std::cout << "char: Non displayable\n";
            std::cout << "int: " << i << "\n";
            std::cout << "float: " << static_cast<float>(i) << "f\n";
            std::cout << "double: " << static_cast<double>(i) << "\n";
        }
        else if (isFloat(lit))
        {
            float f = std::strtof(lit.c_str(), nullptr);
            if (std::isnan(f) || std::isinf(f))
                std::cout << "char: impossible\n";
            else
            {
                char c = static_cast<char>(f);
                if (std::isprint(c))
                    std::cout << "char: " << c << "\n";
                else
                    std::cout << "char: Non displayable\n";
            }
            std::cout << "int: " << static_cast<int>(f) << "\n";
            std::cout << "float: " << static_cast<float>(f) << "f\n";
            std::cout << "double: " << static_cast<double>(f) << "\n";
        }
        else if (isDouble(lit))
        {
            double d = std::strtod(lit.c_str(), nullptr);
            if (std::isnan(d) || std::isinf(d))
                std::cout << "char: impossible\n";
            else
            {
                char c = static_cast<char>(d);
                if (std::isprint(c))
                    std::cout << "char: " << c << "\n";
                else
                    std::cout << "char: Non displayable\n";
            }
            std::cout << "int: " << static_cast<int>(d) << "\n";
            std::cout << "float: " << static_cast<float>(d) << "f\n";
            std::cout << "double: " << static_cast<double>(d) << "\n";
        }
    }
    catch (const std::exception& e)
    {
        std::cout << "Not possible: " << e.what() << std::endl;
    }
}