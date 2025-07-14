/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nzharkev <nzharkev@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 10:39:49 by nzharkev          #+#    #+#             */
/*   Updated: 2025/07/14 13:14:16 by nzharkev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/BitcoinExchange.hpp"
#include <iostream>
#include <fstream>
#include <sstream>


static bool isValidValue(std::string& rateStr, float& rate)
{
    try
    {
        rate = std::stof(rateStr);
        if (rate < 0.0f)
            return false;
        if (rate > 1000.0f)
            return false;
    }
    catch(...)
    {
        return false;
    }
    return true;
}

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cerr << "No file given" << std::endl;
        return 1;
    }
    std::ifstream file(argv[1]);
    if (!file.is_open())
    {
        std::cerr << "Failed to open file " << argv[1]  << std::endl;
        return 1;
    }
    BitcoinExchange db("data.csv");
    std::string line;
    std::getline(file, line);
    while (getline(file, line))
    {
        std::istringstream stream(line);
        std::string date, rateStr;
        float rate;
        size_t pipePos = line.find('|');
        if (pipePos == std::string::npos)
        {
            std::cerr << "Error invalid input on line {" << line << "}" << std::endl;
            continue;
        }
        date = line.substr(0, pipePos);
        rateStr = line.substr(pipePos + 1);
        date.erase(date.find_last_not_of(" \t") + 1);
        date.erase(0, date.find_first_not_of(" \t"));
        rateStr.erase(rateStr.find_last_not_of(" \t") + 1);
        rateStr.erase(0, rateStr.find_first_not_of(" \t"));
        if (!db.isValidDate(date))
        {
            std::cerr << "Invalid date on line {" << line << "}" << std::endl;
            continue;
        }
        if (!isValidValue(rateStr, rate))
        {
            if (rateStr.empty() || rate < 0.0f)
                std::cerr << "Not a positive number" << std::endl;
            else
                std::cerr << "Value is over 1000" << std::endl;
            continue;
        }
        try
        {
            float dayRate = db.getRate(date);
            std::cout << date << " => " << rate << " = " << rate * dayRate << std::endl;
            
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << std::endl;
        }
        
    }
    return 0;
}