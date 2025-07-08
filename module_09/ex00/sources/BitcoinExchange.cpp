/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nzharkev <nzharkev@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-07-07 10:39:53 by nzharkev          #+#    #+#             */
/*   Updated: 2025-07-07 10:39:53 by nzharkev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/BitcoinExchange.hpp"
#include <stdexcept>
#include <sstream>
#include <fstream>
#include <iostream>
#include <ctime>

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const std::string& db) { loadDB(db); }

BitcoinExchange::BitcoinExchange(const BitcoinExchange& copy) : _Rates(copy._Rates) {}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& copy)
{
    if (this != &copy)
    {
        _Rates = copy._Rates;
    }
    return *this;
}

BitcoinExchange::~BitcoinExchange() {}

float BitcoinExchange::getRate(const std::string& date) const
{
    auto it = _Rates.lower_bound(date);
    if (it != _Rates.end() && it->first == date)
        return it->second;
    if (it == _Rates.begin())
        throw std::runtime_error("No earlier date in db");
    --it;
    return it->second;
}

bool BitcoinExchange::isValidDate(const std::string& date) const
{
    if (date.length() != 10 || date[4] != '-' || date[7] != '-')
        return false;
    int y, m, d;
    if (sscanf(date.c_str(), "%d-%d-%d", &y, &m, %d) != 3)
        return false;
    struct tm timeinfo = {};
    timeinfo.tm_year = y - 1900;
    timeinfo.tm_mon = m - 1;
    timeinfo.tm_mday = d;
    timeinfo.tm_hour = 12;
    struct tm copy = timeinfo;
    time_t t  = mktime(&copy);
    if (t == -1)
        return false;
    return  copy.tm_year == timeinfo.tm_year &&
            copy.tm_mon == timeinfo.tm_mon &&
            copy.tm_mday == timeinfo.tm_mday;
}

void BitcoinExchange::loadDB(const std::string& db)
{
    std::fstream file(db);
    if (!file.is_open())
        std::cerr << "Couldn't open the file" << std::endl;
    std::string line;
    std::getline(file, line);
    while (std::getline(file, line))
    {
        std::istringstream iss(line);
        std::string date, rate;
        if (!std::getline(iss, date, ',') || !std::getline(iss, rate))
        {
            
            continue;
        }
        float rateF = std::stof(rate);
        _Rates[date] = rateF;
    }
}