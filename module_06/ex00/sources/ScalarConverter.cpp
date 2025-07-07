/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nzharkev <nzharkev@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 13:02:03 by nzharkev          #+#    #+#             */
/*   Updated: 2025/07/02 12:42:46 by nzharkev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ScalarConventer.hpp"
#include <iostream>
#include <iomanip>
// #include <cstdlib>
// #include <cctype>
#include <cmath>
#include <limits>
// #include <sstream>

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter& ref) { static_cast<void>(ref); }

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& ref) { static_cast<void>(ref); return *this; }

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

/* I use std::stol (string to long) instead of std::stoi (string to int)
 to safely parse the input and check for overflow/underflow beyond the int range (long is a superset of int).
 Once the value is confirmed to be within the int limits, we explicitly cast it
 to int, char, float, and double as required.

 This approach follows the project instructions:
  - It uses an allowed function to convert from a string to a numeric type (any function to convert from a string to an int).
  - It performs the necessary type conversion explicitly (via static_cast).
  - It provides robust error handling for edge cases like overflow.
 Using stol instead of stoi gives us finer control over validation,
 which aligns with the subject's requirement to "do the whole job."*/

void ScalarConverter::convert(const std::string& lit) 
{
    try
    {
        if (isChar(lit))
        {
            char c = lit[0];
            std::cout << "char: " << c << "\n";
            std::cout << "int: " << static_cast<int>(c) << "\n";
            std::cout << std::fixed << std::setprecision(1);
            std::cout << "float: " << static_cast<float>(c) << "f\n";
            std::cout << "double: " << static_cast<double>(c) << "\n";
        }
        else if (isInt(lit))
        {
            long ln = std::stol(lit);
            if (ln < std::numeric_limits<int>::min() || ln > std::numeric_limits<int>::max())
            {
                std::cout << "char: impossible\n";
                std::cout << "int: impossible\n";   
            }
            else
            {
                char c = static_cast<char>(ln);
                if (std::isprint(c))
                    std::cout << "char: " << c << "\n";
                else
                    std::cout << "char: Non displayable\n";
                std::cout << "int: " << ln << "\n";
            }
            std::cout << std::fixed << std::setprecision(1);
            std::cout << "float: " << static_cast<float>(ln) << "f\n";
            std::cout << "double: " << static_cast<double>(ln) << "\n";
        }
        else if (isFloat(lit))
        {
            float f = std::strtof(lit.c_str(), nullptr);
            if (std::isnan(f) || std::isinf(f))
            {    
                std::cout << "char: impossible\n";
                std::cout << "int: impossible\n";
            }
            else
            {
                char c = static_cast<char>(f);
                if (f < 0 || f > 127)
                    std::cout << "char: impossible\n";
                else
                {
                    if (std::isprint(c))
                        std::cout << "char: " << c << "\n";
                    else
                        std::cout << "char: Non displayable\n";
                    }
                std::cout << "int: " << static_cast<int>(f) << "\n";
            }
            std::cout << std::fixed << std::setprecision(1);
            std::cout << "float: " << static_cast<float>(f) << "f\n";
            std::cout << "double: " << static_cast<double>(f) << "\n";
        }
        else if (isDouble(lit))
        {
            double d = std::strtod(lit.c_str(), nullptr);
            if (std::isnan(d) || std::isinf(d))
            {
                std::cout << "char: impossible\n";
                std::cout << "int: impossible\n";
            }
            else
            {
                char c = static_cast<char>(d);
                if (d < 0 || d > 127)
                    std::cout << "char: impossible\n";
                else
                {
                    if (std::isprint(c))
                        std::cout << "char: " << c << "\n";
                    else
                        std::cout << "char: Non displayable\n";
                }
                std::cout << "int: " << static_cast<int>(d) << "\n";
            }
            std::cout << std::fixed << std::setprecision(1);
            std::cout << "float: " << static_cast<float>(d) << "f\n";
            std::cout << "double: " << d << "\n";
        }
        else
        {
            std::cout << "char: impossible\n";
            std::cout << "int: impossible\n";
            std::cout << "float: impossible\n";
            std::cout << "double: impossible\n";
        }

    }
    catch (const std::exception& e)
    {
        std::cout << "Not possible: " << e.what() << std::endl;
    }
}