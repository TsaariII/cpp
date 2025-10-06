/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nzharkev <nzharkev@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 14:10:33 by nzharkev          #+#    #+#             */
/*   Updated: 2025/07/04 14:10:41 by nzharkev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <string>
#include <map>

class BitcoinExchange
{
    private:
        BitcoinExchange(const BitcoinExchange& copy);
        BitcoinExchange& operator=(const BitcoinExchange& copy);
        BitcoinExchange();
        std::map<std::string, float> _Rates;
        void loadDB(const std::string& db);
    public:
        BitcoinExchange(const std::string& db);
        ~BitcoinExchange();
        float getRate(const std::string& date) const;
        bool isValidDate(const std::string& date) const;
};