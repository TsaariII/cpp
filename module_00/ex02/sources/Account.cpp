/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nzharkev <nzharkev@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 13:01:24 by nzharkev          #+#    #+#             */
/*   Updated: 2025/03/22 10:00:34 by nzharkev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Account.hpp"

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

Account::Account(int initial_deposit) : _amount(initial_deposit), _nbDeposits(0), _nbWithdrawals(0)
{
    static int indx;
    _accountIndex = indx;
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";created" << std::endl;
    _totalAmount += initial_deposit;
    indx++;
    _nbAccounts++;
};
Account::~Account()
{
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";closed" << std::endl;
};
void	Account::makeDeposit(int deposit)
{
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";p_amount:"
        << _amount << ";deposit:" << deposit << ";";
    _amount += deposit;
    _totalAmount += deposit;
    std::cout << "amount:" << _amount;
    _nbDeposits += 1;
    _totalNbDeposits += 1;
    std::cout << ";nb_deposits:" << _nbDeposits << std::endl;
};
bool	Account::makeWithdrawal(int withdrawal)
{
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";p_amount:"
        << _amount << ";withdrawal:";
     _amount -= withdrawal;
    if (_amount < 0)
    {
        _amount += withdrawal;
        std::cout << "refused" << std::endl;
        return 0;
    }
    _totalAmount -= withdrawal;
    std::cout << withdrawal << ";amount:" << _amount;
    _nbWithdrawals += 1;
    _totalNbWithdrawals += 1;
    std::cout << ";nb_withdrawals:" << _nbWithdrawals << std::endl;
    return 1;
};
int		Account::checkAmount( void ) const { return _totalAmount; };
void	Account::displayStatus( void ) const
{
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";amount:"
        << _amount << ";deposits:" << _nbDeposits
        << ";withdrawls:" << _nbWithdrawals << std::endl;
};

int	Account::getNbAccounts( void )  { return _nbAccounts; };
int	Account::getTotalAmount( void )  { return _totalAmount; };
int Account::getNbDeposits( void )   { return _totalNbDeposits; };
int	Account::getNbWithdrawals( void )   { return _totalNbWithdrawals; };
void	Account::displayAccountsInfos( void )
{
    _displayTimestamp();
    std::cout << "accounts:" << _nbAccounts << ";total:"
        << _totalAmount << ";deposits:" << _totalNbDeposits
        << ";withdrawls:" << _totalNbWithdrawals << std::endl;
};
void	Account::_displayTimestamp( void )
{
    // [19920104_091532]
    time_t stamp = time(NULL);
    tm *format = std::localtime(&stamp);
    std::cout << "[" << format->tm_year + 1900;
    if (format->tm_mon + 1 < 10)
        std::cout << "0";
    std::cout << format->tm_mon + 1;
    if (format->tm_mday < 10)
        std::cout << "0";
    std::cout << format->tm_mday
        << "_" << format->tm_hour << format->tm_min
        << format->tm_sec << "] ";
};
