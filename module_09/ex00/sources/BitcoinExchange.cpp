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
    char d1, d2;
    std::stringstream s(date);
    s >> y >> d1 >> m >> d2 >> d;
    if (m < 1 || m > 12 || d < 1 || d > 31)
        return false;
    return  true;
}

void BitcoinExchange::loadDB(const std::string& db)
{
    std::fstream file(db);
    if (!file.is_open())
        std::cerr << "Couldn't open the file" << std::endl;
    std::string line;
    std::getline(db, line);
    
}